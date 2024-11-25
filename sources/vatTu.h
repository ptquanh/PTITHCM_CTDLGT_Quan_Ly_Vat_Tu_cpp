#pragma once
#include "./sharedResources.h"
// cai dai ctdl cay AVL
int findMax(int a, int b)
{
    return (a > b) ? a : b;
}

int height(treeVatTu N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalanceFactor(treeVatTu N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

treeVatTu newNode(nodeVatTu data_vt)
{
    treeVatTu node = new dsVatTu();
    node->data_vt = data_vt;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

treeVatTu rightRotate(treeVatTu y)
{
    treeVatTu x = y->left;
    treeVatTu T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = findMax(height(y->left), height(y->right)) + 1;
    x->height = findMax(height(x->left), height(x->right)) + 1;
    return x;
}

treeVatTu leftRotate(treeVatTu x)
{
    treeVatTu y = x->right;
    treeVatTu T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = findMax(height(x->left), height(x->right)) + 1;
    y->height = findMax(height(y->left), height(y->right)) + 1;
    return y;
}

treeVatTu insert(treeVatTu node, nodeVatTu data_vt)
{
    if (node == NULL)
        return newNode(data_vt);
    if (data_vt.MAVT < node->data_vt.MAVT)
        node->left = insert(node->left, data_vt);
    else if (data_vt.MAVT > node->data_vt.MAVT)
        node->right = insert(node->right, data_vt);
    else
        return node;
    node->height = 1 + findMax(height(node->left), height(node->right));
    int balance = getBalanceFactor(node);
    if (balance > 1 && data_vt.MAVT < node->left->data_vt.MAVT)
        return rightRotate(node);
    if (balance < -1 && data_vt.MAVT > node->right->data_vt.MAVT)
        return leftRotate(node);
    if (balance > 1 && data_vt.MAVT > node->left->data_vt.MAVT)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data_vt.MAVT < node->right->data_vt.MAVT)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

treeVatTu minValueNode(treeVatTu node)
{
    treeVatTu current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

treeVatTu deleteNode(treeVatTu root, string MAVT)
{
    if (root == NULL)
        return root;
    if (MAVT < root->data_vt.MAVT)
        root->left = deleteNode(root->left, MAVT);
    else if (MAVT > root->data_vt.MAVT)
        root->right = deleteNode(root->right, MAVT);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            treeVatTu temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            treeVatTu temp = minValueNode(root->right);
            root->data_vt = temp->data_vt;
            root->right = deleteNode(root->right, temp->data_vt.MAVT);
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + findMax(height(root->left), height(root->right));
    int balance = getBalanceFactor(root);
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// tim theo mavt
treeVatTu search(treeVatTu root, string MAVT)
{
    if (root == NULL || root->data_vt.MAVT == MAVT)
    {
        return root;
    }
    if (MAVT < root->data_vt.MAVT)
        return search(root->left, MAVT);

    return search(root->right, MAVT);
}

int countNodes(treeVatTu root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
// ghi tung node vao file ds_vattu
void writeNodeToFile(treeVatTu node, ofstream &fileout)
{
    if (node == nullptr)
        return;
    writeNodeToFile(node->left, fileout);
    fileout << node->data_vt.MAVT << "|"
            << node->data_vt.TENVT << "|"
            << node->data_vt.DVT << "|"
            << node->data_vt.soLuongTon << endl;
    writeNodeToFile(node->right, fileout);
}
// ghi file ds_vattu
void writeFile_dsVatTu(treeVatTu root)
{
    ofstream fileout;
    fileout.open(filePath_VT, ios_base::out);
    int n = countNodes(root);
    if (n == 0)
    {
        drawTableErrors("Khong co du lieu vat tu", true);
        Sleep(1500);
        drawTableErrors("", true);
        return;
    }
    if (!fileout.is_open())
    {
        cout << "Khong the mo file ds_VatTu.txt" << endl;
        return;
    }
    if (root == nullptr)
    {
        cout << "Cay rong khong co du lieu de ghi" << endl;
        return;
    }
    if (root != NULL)
    {
        cout << endl;
    }
    writeNodeToFile(root, fileout);
    fileout.close();
    drawTableErrors("Luu vat tu vao file thanh cong", true);
    Sleep(1500);
    drawTableErrors("", true);
}
void readFile_dsVatTu(treeVatTu &root, bool &isOpened)
{
    bool hasError;
    isOpened = true;
    ifstream filein;
    filein.open(filePath_VT, ios_base::in);
    if (!filein.is_open())
    {
        isOpened = false;
        return;
    }

    string line;
    while (getline(filein, line))
    {
        // Bỏ qua dòng trống
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == string::npos)
            continue;

        // Tạo stringstream để xử lý dòng dữ liệu
        stringstream ss(line);
        nodeVatTu data_vt;

        // Đọc từng phần của dữ liệu
        getline(ss, data_vt.MAVT, '|');
        for (char &c : data_vt.MAVT)
        {
            c = std::toupper(c);
        }
        getline(ss, data_vt.TENVT, '|');
        data_vt.TENVT = normalizeString(data_vt.TENVT, hasError);
        getline(ss, data_vt.DVT, '|');
        data_vt.DVT = normalizeString(data_vt.DVT, hasError);
        ss >> data_vt.soLuongTon;
        formatInputVT(data_vt.MAVT, data_vt.TENVT, data_vt.DVT, data_vt.soLuongTon);
        // Kiểm tra xem đọc dữ liệu có thành công không
        if (!ss.fail())
        {
            root = insert(root, data_vt);
        }
        else
        {
            cout << "Loi: Khong the doc du lieu tu dong: " << line << endl;
        }
    }
    filein.close();
}
void suaVatTu(treeVatTu &root, string MAVT, int x, int y, bool &isESC, bool &isSaved)
{
    nodeVatTu input;
    input.MAVT = "";
    input.TENVT = "";
    input.DVT = "";
    input.soLuongTon = 0;
    string errorMessage;
    int currentRow = 1;
    bool hasError;
    string result;
    int numResult;
    bool moveNext;
    string tempInput;
    isESC, isSaved = false;
    treeVatTu node = search(root, MAVT);
    if (node == NULL)
    {
        cout << "Khong tim thay vat tu voi ma " << MAVT << endl;
        return;
    }
    input.MAVT = node->data_vt.MAVT;
    input.TENVT = node->data_vt.TENVT;
    input.DVT = node->data_vt.DVT;
    input.soLuongTon = node->data_vt.soLuongTon;
    while (true)
    {
        displayField(x + 87, y + 4, input.MAVT, false, 10);
        displayField(x + 87, y + 6, input.TENVT, currentRow == 1, 20);
        displayField(x + 87, y + 8, input.DVT, currentRow == 2, 6);
        displayField(x + 87, y + 10, input.soLuongTon > 0 ? to_string(input.soLuongTon) : "", false, 6);
        switch (currentRow)
        {
        case 1:
        {
            result = inputString(x + 87, y + 6, input.TENVT, 20, "Ten vat tu", moveNext, true);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ten vat tu chua ky tu khong hop le";
                drawTableErrors(errorMessage, true);
                continue;
            }
            drawTableErrors("", true);
            input.TENVT = tempInput;
            formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
            break;
        }
        case 2:
        {
            result = inputString(x + 87, y + 8, input.DVT, 6, "Don vi tinh", moveNext, true);
            if (result == "ESC")
                goto escButton;
            if (result == "F10")
                goto saveButton;
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Don vi tinh chua ky tu khong hop le";
                drawTableErrors(errorMessage, true);

                continue;
            }
            drawTableErrors("", true);
            input.DVT = tempInput;
            formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
            break;
        }
        escButton:
        {
            isESC = true;
            return;
        }
        saveButton:
        {
            if (!moveNext && !input.MAVT.empty() && !input.TENVT.empty() &&
                !input.DVT.empty() && input.soLuongTon > 0)
            {
                node->data_vt.MAVT = input.MAVT;
                node->data_vt.TENVT = input.TENVT;
                node->data_vt.DVT = input.DVT;
                node->data_vt.soLuongTon = input.soLuongTon;
                isSaved = true;
                writeFile_dsVatTu(root);
                return;
            }
        }
        }
        if (moveNext)
        {
            currentRow = (currentRow < 2) ? currentRow + 1 : 2;
        }
        else
        {
            currentRow = (currentRow > 1) ? currentRow - 1 : 1;
        }
    }
}

void nhapVatTu(treeVatTu &root, int x, int y, string mavt, int soLuong, bool isSmallScreen, bool isInCTHD)
{
    nodeVatTu input;
    input.MAVT = "";
    input.TENVT = "";
    input.DVT = "";
    input.soLuongTon = 0;
    string errorMessage;
    int currentRow = 0;
    bool hasError;
    string result;
    int numResult;
    bool moveNext;
    string tempInput;
    if (!isInCTHD)
    {
        while (true)
        {
            displayField(x + 87, y + 4, input.MAVT, currentRow == 0, 10);
            displayField(x + 87, y + 6, input.TENVT, currentRow == 1, 20);
            displayField(x + 87, y + 8, input.DVT, currentRow == 2, 6);
            displayField(x + 87, y + 10, input.soLuongTon > 0 ? to_string(input.soLuongTon) : "", currentRow == 3, 6);

            switch (currentRow)
            {
            case 0:
            {
                result = inputString(x + 87, y + 4, input.MAVT, 10, "Ma vat tu", moveNext, isSmallScreen);
                if (result == "ESC")
                    goto escButton;
                if (result == "F10")
                    goto saveButton;
                tempInput = normalizeString(result, hasError);
                if (hasError)
                {
                    drawTableErrors("Ma vat tu chua ky tu khong hop le", isSmallScreen);
                    continue;
                }
                for (char &c : tempInput)
                {
                    c = std::toupper(c);
                }
                if (search(root, tempInput) != NULL)
                {
                    drawTableErrors("Ma vat tu da ton tai", isSmallScreen);
                    continue;
                }
                drawTableErrors("", isSmallScreen);
                input.MAVT = tempInput;
                formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
                break;
            }
            case 1:
            {
                result = inputString(x + 87, y + 6, input.TENVT, 20, "Ten vat tu", moveNext, isSmallScreen);
                if (result == "ESC")
                    goto escButton;
                if (result == "F10")
                    goto saveButton;
                tempInput = normalizeString(result, hasError);
                if (hasError)
                {
                    drawTableErrors("Ten vat tu chua ky tu khong hop le", isSmallScreen);
                    continue;
                }
                drawTableErrors("", isSmallScreen);
                input.TENVT = tempInput;
                formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
                break;
            }
            case 2:
            {
                result = inputString(x + 87, y + 8, input.DVT, 6, "Don vi tinh", moveNext, isSmallScreen);
                if (result == "ESC")
                    goto escButton;
                if (result == "F10")
                    goto saveButton;
                tempInput = normalizeString(result, hasError);
                if (hasError)
                {
                    drawTableErrors("Don vi tinh chua ky tu khong hop le", isSmallScreen);
                    continue;
                }
                drawTableErrors("", isSmallScreen);
                input.DVT = tempInput;
                formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
                break;
            }
            case 3:
            {
                numResult = inputNumber(x + 87, y + 10, input.soLuongTon, 6, "So luong ton", moveNext, isSmallScreen);
                if (numResult == -1)
                    goto escButton;
                if (numResult == -10)
                    goto saveButton;
                if (numResult == 0)
                {
                    drawTableErrors("So luong ton lon hon 0", isSmallScreen);
                    continue;
                }
                drawTableErrors("", isSmallScreen);
                input.soLuongTon = numResult;
                formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
                break;
            }
            escButton:
            {
                ShowCur(false);
                drawTableErrors("Dang thoat chuong trinh...", isSmallScreen);
                Sleep(1500);
                drawTableErrors("", isSmallScreen);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            saveButton:
            {
                ShowCur(false);
                if (!moveNext && !input.MAVT.empty() && !input.TENVT.empty() &&
                    !input.DVT.empty() && input.soLuongTon > 0)
                {
                    root = insert(root, input);
                    writeFile_dsVatTu(root);
                    drawTableErrors("Them vat tu thanh cong", isSmallScreen);
                    Sleep(1500);
                    drawTableErrors("", isSmallScreen);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    return;
                }
                else
                {
                    drawTableErrors("Thieu thong tin. Chua them vat tu", isSmallScreen);
                    Sleep(1500);
                    drawTableErrors("", isSmallScreen);
                }
            }
            }
            if (moveNext)
            {
                currentRow = (currentRow < 3) ? currentRow + 1 : 3;
            }
            else
            {
                currentRow = (currentRow > 0) ? currentRow - 1 : 0;
            }
        }
    }
    else
    {
        currentRow = 1;
        char key;
        while (true)
        {
            input.MAVT = mavt;
            input.soLuongTon = soLuong;
            displayField(x + 87, y + 4, input.MAVT, false, 10);
            displayField(x + 87, y + 6, input.TENVT, currentRow == 1, 20);
            displayField(x + 87, y + 8, input.DVT, currentRow == 2, 6);

            switch (currentRow)
            {
            // case 0:
            // {
            //     // result = inputString(x + 87, y + 4, input.MAVT, 10, "Ma vat tu", moveNext, isSmallScreen);
            //     // if (result == "ESC")
            //     //     goto escButton;
            //     // if (result == "F10")
            //     //     goto saveButton;
            //     tempInput = normalizeString(mavt, hasError);
            //     if (hasError)
            //     {
            //         drawTableErrors("Ma vat tu chua ky tu khong hop le", isSmallScreen);
            //         continue;
            //     }

            //     if (search(root, tempInput) != NULL)
            //     {
            //         drawTableErrors("Ma vat tu da ton tai", isSmallScreen);
            //         continue;
            //     }
            //     drawTableErrors("", isSmallScreen);
            //     input.MAVT = tempInput;
            //     formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
            //     break;
            // }
            case 1:
            {
                result = inputString(x + 87, y + 6, input.TENVT, 20, "Ten vat tu", moveNext, isSmallScreen);
                if (result == "ESC")
                    goto escButton;
                if (result == "F10")
                    goto saveButton;
                tempInput = normalizeString(result, hasError);
                if (hasError)
                {
                    drawTableErrors("Ten vat tu chua ky tu khong hop le", isSmallScreen);
                    continue;
                }
                drawTableErrors("", isSmallScreen);
                input.TENVT = tempInput;
                formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
                break;
            }
            case 2:
            {
                result = inputString(x + 87, y + 8, input.DVT, 6, "Don vi tinh", moveNext, isSmallScreen);
                if (result == "ESC")
                    goto escButton;
                if (result == "F10")
                    goto saveButton;
                tempInput = normalizeString(result, hasError);
                if (hasError)
                {
                    drawTableErrors("Don vi tinh chua ky tu khong hop le", isSmallScreen);
                    continue;
                }
                drawTableErrors("", isSmallScreen);
                input.DVT = tempInput;
                formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
                break;
            }
            // case 3:
            // {
            //     // numResult = inputNumber(x + 87, y + 10, input.soLuongTon, 6, "So luong ton", moveNext, isSmallScreen);
            //     if (numResult == -1)
            //         goto escButton;
            //     if (numResult == -10)
            //         goto saveButton;
            //     if (numResult == 0)
            //     {
            //         drawTableErrors("So luong ton lon hon 0", isSmallScreen);
            //         continue;
            //     }
            //     drawTableErrors("", isSmallScreen);
            //     input.soLuongTon = numResult;
            //     formatInputVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
            //     break;
            // }
            escButton2:
            {
                ShowCur(false);
                drawTableErrors("Dang thoat chuong trinh...", isSmallScreen);
                Sleep(1500);
                drawTableErrors("", isSmallScreen);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            saveButton2:
            {
                ShowCur(false);
                if (!moveNext && !input.MAVT.empty() && !input.TENVT.empty())
                {
                    root = insert(root, input);
                    drawTableErrors("Them vat tu thanh cong", isSmallScreen);
                    Sleep(1500);
                    drawTableErrors("", isSmallScreen);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    return;
                }
                else
                {
                    drawTableErrors("Thieu thong tin. Chua them vat tu", isSmallScreen);
                    Sleep(1500);
                    drawTableErrors("", isSmallScreen);
                }
            }
            }
            if (moveNext)
            {
                currentRow = (currentRow < 3) ? currentRow + 1 : 2;
            }
            else
            {
                currentRow = (currentRow > 1) ? currentRow - 1 : 1;
            }
        }
    }
}
bool kiemTraVatTuTrongCTHD(dsNhanVien &ds_nv, string maVT)
{
    // Duyệt qua từng nhân viên
    for (int i = 0; i < ds_nv.countNV; i++)
    {
        ptr_DSHD current_hd = ds_nv.nodes[i]->firstDSHD;

        // Duyệt qua từng hóa đơn của nhân viên
        while (current_hd != nullptr)
        {
            ptr_DSCTHD current_cthd = current_hd->data_hd.firstCTHD;

            // Duyệt qua từng chi tiết hóa đơn
            while (current_cthd != nullptr)
            {
                if (current_cthd->data_cthd.MAVT == maVT)
                {
                    return true; // Tìm thấy vật tư trong chi tiết hóa đơn
                }
                current_cthd = current_cthd->next;
            }
            current_hd = current_hd->next;
        }
    }
    return false; // Không tìm thấy vật tư trong bất kỳ chi tiết hóa đơn nào
}
// xoa vt theo mavt
void xoaVatTu(treeVatTu &root, dsNhanVien &ds_nv, string MAVT, int x, int y, bool &isESC, bool &isSaved)
{
    nodeVatTu input;
    input.MAVT = "";
    input.TENVT = "";
    input.DVT = "";
    input.soLuongTon = 0;
    isESC = false;
    isSaved = false;
    bool hasError;
    if (root == NULL)
    {
        cout << "Danh sach vat tu rong ";
        return;
    }
    treeVatTu node = search(root, MAVT);
    if (node == NULL)
    {
        cout << "Khong tim thay ma vt" << MAVT << endl;
        return;
    }

    input.MAVT = node->data_vt.MAVT;
    input.TENVT = node->data_vt.TENVT;
    input.DVT = node->data_vt.DVT;
    input.soLuongTon = node->data_vt.soLuongTon;

    displayField(x + 87, y + 4, input.MAVT, false, 10);
    displayField(x + 87, y + 6, input.TENVT, false, 20);
    displayField(x + 87, y + 8, input.DVT, false, 6);
    displayField(x + 87, y + 10, input.soLuongTon > 0 ? to_string(input.soLuongTon) : "", false, 6);

    char key;
    while (true)
    {
        key = getch();
        switch (key)
        {
        case ESC:
            isESC = true;
            return;
        case F10:
            if (kiemTraVatTuTrongCTHD(ds_nv,MAVT))
            {
                drawTableErrors("Khong the xoa vat tu trong hoa don", true);
                Sleep(1500);
                drawTableErrors("", true);
                fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                return;
            }
            else
            {
                if (input.soLuongTon > 0)
                {
                    drawTableErrors("Khong the xoa vat tu so luong > 0", true);
                    Sleep(1500);
                    drawTableErrors("", true);
                    fillAreaColor(x + 69, y, 41, 16, LIGHTGRAY);
                    return;
                }
                else
                {
                    root = deleteNode(root, MAVT);
                    writeFile_dsVatTu(root);
                    isSaved = true;
                    return;
                }
            }
        }
    }
}
// =======================================================================
void storeInorder(treeVatTu root, treeVatTu arr[], int *index)
{
    if (root == NULL)
        return;

    storeInorder(root->left, arr, index);
    arr[*index] = root;
    (*index)++;
    storeInorder(root->right, arr, index);
}

void inDanhSachVatTu(treeVatTu root, int pageNumber, int selectedRow, int x)
{
    int n = countNodes(root);
    if (n == 0)
    {
        drawTableErrors("Khong co du lieu vat tu", true);
        Sleep(1500);
        drawTableErrors("", true);
        return;
    }
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSortVatTu(arr, 0, n - 1);

    int startIndex = (pageNumber - 1) * ROWS;
    int endIndex = min(startIndex + ROWS, n);

    int currentRow = 5;
    for (int i = startIndex; i < endIndex; i++)
    {
        gotoxy(x + 3, currentRow);
        if (selectedRow == -1)
            cout << arr[i]->data_vt.MAVT;
        else if (i - startIndex == selectedRow)
        {
            Highlight(LIGHTBLUE);
            cout << arr[i]->data_vt.MAVT;
            setColorByRequest(LIGHTGRAY, BLACK);
        }
        else
        {
            cout << arr[i]->data_vt.MAVT;
        }
        gotoxy(x + 18, currentRow);
        cout << arr[i]->data_vt.TENVT;
        gotoxy(x + 43, currentRow);
        cout << arr[i]->data_vt.DVT;
        gotoxy(x + 54, currentRow);
        cout << arr[i]->data_vt.soLuongTon;
        currentRow++;
    }
    // in so trang
    int totalPages = ceil((float)n / ROWS);
    gotoxy(6, 26);
    cout << "TAB: Di chuyen den trang can tim";
    gotoxy(52, 26);
    cout << "<- Trang " << pageNumber << "/" << totalPages << " ->";
    delete[] arr;
}
// Hàm đếm số kết quả tìm được
int countSearchResults(treeVatTu root, const string &kyTu)
{
    if (root == nullptr)
        return 0;

    int count = 0;
    if (hasCharacter(kyTu, root->data_vt.TENVT))
    {
        count = 1;
    }

    count += countSearchResults(root->left, kyTu);
    count += countSearchResults(root->right, kyTu);

    return count;
}
// Hàm lưu kết quả tìm kiếm vào mảng
void storeSearchResults(treeVatTu root, const string &kyTu, treeVatTu results[], int &index)
{
    if (root == nullptr)
        return;

    if (hasCharacter(kyTu, root->data_vt.TENVT))
    {
        results[index++] = root;
    }

    storeSearchResults(root->left, kyTu, results, index);
    storeSearchResults(root->right, kyTu, results, index);
}

void displaySearchResults(treeVatTu *results, int n, int pageNumber, int selectedRow, int x, const string &searchStr)
{
    bool hasError;
    setColorByRequest(LIGHTGRAY, BLACK);
    int currentRow = 5;
    int startIndex = (pageNumber - 1) * ROWS;
    int endIndex = min(startIndex + ROWS, n);
    for (int i = startIndex; i < endIndex; i++)
    {
        gotoxy(x + 3, currentRow);
        if (selectedRow == -1)
            cout << results[i]->data_vt.MAVT;
        else if (i - startIndex == selectedRow)
        {
            Highlight(LIGHTBLUE);
            cout << results[i]->data_vt.MAVT;
            setColorByRequest(LIGHTGRAY, BLACK);
        }
        else
        {
            cout << results[i]->data_vt.MAVT;
        }
        setColorByRequest(LIGHTGRAY, BLACK);
        gotoxy(x + 18, currentRow);
        string tenVT = results[i]->data_vt.TENVT;
        string normalizedSearch = normalizeString(searchStr, hasError);
        if (!hasError)
        {
            printHighlightedText(tenVT, normalizedSearch);
        }
        else
        {
            cout << tenVT;
        }
        gotoxy(x + 43, currentRow);
        cout << results[i]->data_vt.DVT;
        gotoxy(x + 54, currentRow);
        cout << results[i]->data_vt.soLuongTon;
        currentRow++;
    }
    // in so trang
    int totalPages = ceil((float)n / ROWS);
    gotoxy(52, 26);
    cout << "<- Trang " << pageNumber << "/" << totalPages << " ->";
    setColorByRequest(LIGHTGRAY, BLACK);
}

void timKiemTenVatTu(treeVatTu root, int x, int y, treeVatTu &selectedResult, bool &isESC)
{
    static string searchHistory[10];
    static int historyCount = 0;
    static int historyIndex = -1;
    static string searchStr = "";
    string currentInput = searchStr;
    int cursorPos = currentInput.length();
    bool hasError;
    bool isSearching = true;
    int selectedRow = -1;
    bool isViewingResults = false;
    int n = countNodes(root);
    treeVatTu *results = new treeVatTu[n];
    int resultCount = 0;
    int currentPage = 1;

    while (isSearching)
    {
        int totalPages = ceil((float)resultCount / ROWS);
        int startIndex = (currentPage - 1) * ROWS;
        int itemsOnPage = min(ROWS, resultCount - startIndex);

        ShowCur(true);
        setColorByRequest(BLACK, WHITE);
        gotoxy(x + 88, y + 4);
        cout << string(20, ' ');
        gotoxy(x + 88, y + 4);
        cout << currentInput;
        gotoxy(x + 88 + cursorPos, y + 4);

        int key = _getch();
        if (key == 224 || key == 0)
        {
            key = _getch();
            switch (key)
            {
            case LEFT:
                if (!isViewingResults && cursorPos > 0)
                    cursorPos--;
                else if (isViewingResults && currentPage > 1)
                {
                    currentPage--;
                    selectedRow = 0;
                    clearTablePrint(x);
                }
                break;

            case RIGHT:
                if (!isViewingResults && cursorPos < currentInput.length())
                    cursorPos++;
                else if (isViewingResults && currentPage < totalPages)
                {
                    currentPage++;
                    selectedRow = 0;
                    clearTablePrint(x);
                }
                break;

            case UP:
                if (isViewingResults && resultCount > 0)
                {
                    if (selectedRow > 0)
                        selectedRow--;
                    else if (selectedRow <= 0)
                        selectedRow = itemsOnPage - 1;
                }
                else if (!isViewingResults && historyCount > 0)
                {
                    if (historyIndex < historyCount - 1)
                    {
                        historyIndex++;
                        currentInput = searchHistory[historyIndex];
                        cursorPos = currentInput.length();
                        searchStr = currentInput;
                    }
                }
                break;

            case DOWN:
                if (isViewingResults && resultCount > 0)
                {
                    if (selectedRow < itemsOnPage - 1)
                        selectedRow++;
                    else if (selectedRow >= itemsOnPage - 1)
                        selectedRow = 0;
                }
                else if (!isViewingResults && historyCount > 0)
                {
                    if (historyIndex > 0)
                    {
                        historyIndex--;
                        currentInput = searchHistory[historyIndex];
                        cursorPos = currentInput.length();
                        searchStr = currentInput;
                    }
                    else if (historyIndex == 0)
                    {
                        historyIndex = -1;
                        currentInput = "";
                        cursorPos = 0;
                        searchStr = "";
                    }
                }
                break;

            case HOME:
                if (!isViewingResults)
                    cursorPos = 0;
                break;

            case END:
                if (!isViewingResults)
                    cursorPos = currentInput.length();
                break;

            case DEL:
                if (!isViewingResults && cursorPos < currentInput.length())
                {
                    currentInput.erase(cursorPos, 1);
                    searchStr = currentInput;
                }
                break;
            }

            if (isViewingResults)
            {
                for (int currentRow = 5; currentRow <= ROWS + 4; currentRow++)
                {
                    for (int i = x + 3; i < x + 15; i++)
                    {
                        if (currentRow == selectedRow + 5)
                        {
                            SetBGColor(LIGHTGRAY);
                            gotoxy(i, currentRow);
                            cout << " ";
                        }
                    }
                }
                displaySearchResults(results, resultCount, currentPage, selectedRow, x, currentInput);
            }
            continue;
        }

        switch (key)
        {
        case ENTER:
            if (isViewingResults && resultCount > 0)
            {
                int actualIndex = (currentPage - 1) * ROWS + selectedRow;
                if (actualIndex < resultCount)
                {
                    selectedResult = results[actualIndex];
                    return;
                }
            }
            else if (!currentInput.empty())
            {
                bool isDuplicate = false;
                selectedRow = 0;
                for (int i = 0; i < historyCount; i++)
                {
                    if (searchHistory[i] == currentInput)
                    {
                        isDuplicate = true;
                        break;
                    }
                }

                if (!isDuplicate)
                {
                    for (int i = historyCount; i > 0; i--)
                    {
                        if (i < 10)
                        {
                            searchHistory[i] = searchHistory[i - 1];
                        }
                    }
                    searchHistory[0] = currentInput;
                    if (historyCount < 10)
                        historyCount++;
                }
                historyIndex = -1;
                isViewingResults = true;
            }
            break;

        case ESC:
            if (isViewingResults)
            {
                isViewingResults = false;
                selectedRow = -1;
                ShowCur(false);
                drawTableErrors("Dang thoat che do xem...", true);
                Sleep(1500);
                drawTableErrors("", true);
                ShowCur(true);
            }
            else
            {
                delete[] results;
                isESC = true;
                return;
            }
            break;

        case BACKSPACE:
            if (!isViewingResults && cursorPos > 0)
            {
                currentInput.erase(cursorPos - 1, 1);
                cursorPos--;
                searchStr = currentInput;
            }
            break;

        case TAB:
            if (resultCount > 0)
            {
                isViewingResults = !isViewingResults;
                if (!isViewingResults)
                    selectedRow = 0;
            }
            break;

        default:
            if (!isViewingResults && currentInput.length() < 20 && isValidChar(key))
            {
                if (cursorPos == currentInput.length())
                {
                    currentInput += (char)key;
                }
                else
                {
                    currentInput.insert(cursorPos, 1, (char)key);
                }
                cursorPos++;
                searchStr = currentInput;
            }
        }

        clearTablePrint(x);

        string tempInput = normalizeString(searchStr, hasError);
        if (hasError)
        {
            drawTableErrors("Du lieu nhap khong hop le", true);
            continue;
        }
        drawTableErrors("", true);

        if (!searchStr.empty())
        {
            resultCount = countSearchResults(root, tempInput);

            if (resultCount == 0)
            {
                drawTableErrors("Khong tim thay '" + searchStr + "'", true);
                continue;
            }

            int index = 0;
            storeSearchResults(root, tempInput, results, index);
            quickSortVatTu(results, 0, resultCount - 1);
            displaySearchResults(results, resultCount, currentPage, selectedRow, x, currentInput);
        }
    }
    delete[] results;
}