#pragma once
// #include "../libraries/khaibao.h"
// #include "../libraries/mylib.h"
#include "../screens/doHoa.cpp"
#define ROWS 20
const int searchHighlightColor = 1;
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
    if (!fileout.is_open())
    {
        cout << "Khong the mo file de ghi ds_VatTu.txt" << endl;
        return;
    }
    if (root == nullptr)
    {
        cout << "Cay nhap lieu rong, khong co du lieu de ghi." << endl;
        return;
    }
    if (root != NULL)
    {
        cout << endl;
    }
    writeNodeToFile(root, fileout);
    fileout.close();
}
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

treeVatTu deleteNode(treeVatTu root, const string &MAVT)
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
treeVatTu search(treeVatTu root, const string &MAVT)
{
    if (root == NULL || root->data_vt.MAVT == MAVT)
    {
        return root;
    }
    if (MAVT < root->data_vt.MAVT)
        return search(root->left, MAVT);

    return search(root->right, MAVT);
}
// chinh sua vt theo mavt
void chinhSuaVatTu(treeVatTu &root)
{
    string MAVT;
    cout << "Nhap Ma Vat Tu can chinh sua: ";
    cin >> MAVT;
    cin.ignore();
    treeVatTu node = search(root, MAVT);
    if (node == NULL)
    {
        cout << "Khong tim thay vat tu voi ma " << MAVT << endl;
        return;
    }

    cout << "Thong tin hien tai:" << endl;
    cout << "Ma vat tu: " << node->data_vt.MAVT << ", Ten: " << node->data_vt.TENVT
         << ", DVT: " << node->data_vt.DVT << ", So luong ton: " << node->data_vt.soLuongTon << endl;

    cout << "Nhap Ten Vat Tu moi (Enter de giu nguyen): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty())
        node->data_vt.TENVT = newName;

    cout << "Nhap Don Vi Tinh moi (Enter de giu nguyen): ";
    string newDVT;
    getline(cin, newDVT);
    if (!newDVT.empty())
        node->data_vt.DVT = newDVT;
    cout << "Da cap nhat thong tin vat tu." << endl;
}
// xoa vt theo mavt
void xoaVatTu(treeVatTu &root)
{
    string MAVT;
    cout << "Nhap Ma Vat Tu can xoa: ";
    cin >> MAVT;
    cin.ignore();

    treeVatTu node = search(root, MAVT);
    if (node == NULL)
    {
        cout << "Khong tim thay vat tu voi ma " << MAVT << endl;
        return;
    }

    char confirm;
    cout << "Ban co chac chan muon xoa vat tu nay? (y/n): ";
    cin >> confirm;
    cin.ignore();

    if (confirm == 'y' || confirm == 'Y')
    {
        root = deleteNode(root, MAVT);
        cout << "Da xoa vat tu voi ma " << MAVT << endl;
    }
    else
    {
        cout << "Huy bo xoa vat tu." << endl;
    }
}

void formatMAVT(string &MAVT, string &TENVT, string &DVT, int &SLT)
{
    if (MAVT.length() > 10)
    {
        MAVT = MAVT.substr(0, 10);
    }
    if (TENVT.length() > 20)
    {
        TENVT = TENVT.substr(0, 20);
    }
    if (DVT.length() > 6)
    {
        DVT = DVT.substr(0, 6);
    }
    string sltStr = to_string(SLT);
    if (sltStr.length() > 6)
    {
        sltStr = sltStr.substr(0, 6);
        SLT = stoi(sltStr);
    }
    if (SLT < 0) // Đảm bảo số lượng không âm
    {
        SLT = 0;
    }
}
// kiem tra ki tu hop le
bool isValidChar(char c)
{
    // Chấp nhận chữ cái (A-Z, a-z)
    bool isLetter = (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
    // Chấp nhận khoảng trắng
    bool isSpace = (c == 32);
    // Chấp nhận số (0-9)
    bool isNumber = (c >= 48 && c <= 57);

    return isLetter || isSpace || isNumber;
}
// chuan hoa ki tu
string normalizeString(const string &input, bool &hasError)
{
    hasError = false;
    string result;
    // Kiểm tra ký tự không hợp lệ
    for (char c : input)
    {
        if (!isValidChar(c))
        {
            cout << "Loi: Ky tu '" << c << "' khong hop le!\n";
            cout << "Chi chap nhan chu cai (A-Z, a-z), so (0-9) va khoang trang.\n";
            hasError = true;
            return input;
        }
    }

    // Nếu chuỗi rỗng hoặc chỉ có khoảng trắng
    if (input.find_first_not_of(' ') == string::npos)
    {
        // cout << "Loi: Chuoi khong duoc rong hoac chi chua khoang trang!\n";
        hasError = true;
        return input;
    }

    // Bỏ khoảng trắng ở đầu và cuối
    int start = 0, end = input.length() - 1;
    while (start <= end && input[start] == ' ')
        start++;
    while (end >= start && input[end] == ' ')
        end--;

    // Xử lý khoảng trắng giữa các từ và chuẩn hóa chữ hoa/thường
    bool prevSpace = false;
    bool newWord = true;
    for (int i = start; i <= end; i++)
    {
        char currentChar = input[i];
        if (currentChar == ' ')
        {
            if (!prevSpace)
            {
                result += ' ';
                prevSpace = true;
                newWord = true;
            }
        }
        else
        {
            if (newWord && isalpha(currentChar))
            {
                // Chữ cái đầu tiên của từ viết hoa
                result += toupper(currentChar);
            }
            else if (isalpha(currentChar))
            {
                // Các chữ cái còn lại viết thường
                result += tolower(currentChar);
            }
            else
            {
                // Giữ nguyên các ký tự số
                result += currentChar;
            }
            prevSpace = false;
            newWord = false;
        }
    }
    return result;
}
// doc file ds_vattu
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
        getline(ss, data_vt.TENVT, '|');
        data_vt.TENVT = normalizeString(data_vt.TENVT, hasError);
        getline(ss, data_vt.DVT, '|');
        data_vt.DVT = normalizeString(data_vt.DVT, hasError);
        ss >> data_vt.soLuongTon;
        formatMAVT(data_vt.MAVT, data_vt.TENVT, data_vt.DVT, data_vt.soLuongTon);
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
// int currentRowFill()
// {
//     char key;
//     int currentRow = 0;
//     while (true)
//     {
//         key = getch();
//         switch (key)
//         {
//         case UP:
//             if (currentRow > 0)
//                 currentRow--;
//             else
//                 currentRow = 3;

//             break;
//         case DOWN:
//             if (currentRow < 3)
//                 currentRow++;
//             else
//                 currentRow = 0;
//             break;
//         }
//         return currentRow;
//     }
// }
// // nhap vat tu
// void nhapVatTu(treeVatTu &root, int x, int y)
// {
//     nodeVatTu data_vt;
//     string MAVT, tenVT, dvt;
//     int slt;
//     bool isValidMAVT = false;
//     bool hasError;
//     int currentRow;
//     // Nhập và kiểm tra MAVT

//     gotoxy(0, 0);
//     currentRow = currentRowFill();
//     cout << currentRow;

//     /*switch (currentRow)
//     {
//     case 0:
//         do
//         {
//             setColorByRequest(WHITE, BLACK);
//             gotoxy(x + 88, y + 4);
//             getline(cin, MAVT);
//             treeVatTu result = search(root, MAVT);
//             formatMAVT(MAVT, tenVT, dvt, slt);
//             // MAVT = formatMAVT(MAVT, tenVT);
//             if (result != NULL)
//             {
//                 cout << "Loi: Ma vat tu '" << MAVT << "' da ton tai trong he thong!\n";
//                 cout << "Vui long nhap ma vat tu khac.\n";
//                 isValidMAVT = false;
//             }
//             else
//             {
//                 data_vt.MAVT = MAVT;
//                 isValidMAVT = true;
//             }
//         } while (!isValidMAVT);
//         break;
//     case 1:
//         do
//         {
//             setColorByRequest(WHITE, BLACK);
//             gotoxy(x + 88, y + 6);
//             getline(cin, tenVT);
//             formatMAVT(MAVT, tenVT, dvt, slt);
//             tenVT = normalizeString(tenVT, hasError);
//             if (!hasError && tenVT.empty())
//             {
//                 cout << "Loi: Ten vat tu khong duoc de trong!\n";
//                 hasError = true;
//             }
//         } while (hasError);
//         data_vt.TENVT = tenVT;
//         break;
//     case 2:
//         do
//         {
//             setColorByRequest(WHITE, BLACK);
//             gotoxy(x + 88, y + 8);
//             getline(cin, dvt);
//             formatMAVT(MAVT, tenVT, dvt, slt);
//             dvt = normalizeString(dvt, hasError);
//             if (!hasError && dvt.empty())
//             {
//                 cout << "Loi: Don vi tinh khong duoc de trong!\n";
//                 hasError = true;
//             }
//         } while (hasError);
//         data_vt.DVT = dvt;
//         break;
//     case 3:
//         setColorByRequest(WHITE, BLACK);
//         gotoxy(x + 88, y + 10);
//         cin >> data_vt.soLuongTon;
//         formatMAVT(MAVT, tenVT, dvt, slt);
//         cin.ignore();
//         break;
//     }*/
//     // root = insert(root, data_vt);
// }

void displayField(int x, int y, const string &value, bool isActive, int maxLength)
{
    // Luôn có nền màu, chỉ thay đổi màu nền khi active
    if (isActive)
    {
        SetBGColor(BLUE);
    }
    else
    {
        SetBGColor(DARKGRAY); // Màu nền cho trường không active
    }
    SetColor(WHITE);

    gotoxy(x, y);
    cout << string(maxLength, ' '); // Xóa vùng hiển thị
    gotoxy(x, y);
    cout << value;

    if (isActive)
    {
        ShowCurAtXY(x + value.length(), y, true);
    }
    SetBGColor(BLACK); // Reset màu nền
    SetColor(WHITE);   // Reset màu chữ
}

string inputString(int x, int y, string current, int maxLength, string fieldName, bool &moveNext)
{
    string result = current;
    char key;
    bool isEditing = true;
    string errorMessage;
    while (isEditing)
    {
        displayField(x, y, result, true, maxLength);
        key = getch();

        if (key == ESC)
        {
            moveNext = false;
            return "ESC";
        }
        if (key == F4)
        {
            moveNext = false;
            return "F4";
        }
        if (key == ENTER)
        {
            if (result.empty())
            {
                // gotoxy(x + 30, y);
                errorMessage = fieldName + " khong duoc de trong!";
                drawTableErrors(5, 2, errorMessage);
                // Sleep(1000);
                // gotoxy(x + 30, y);
                // cout << string(50, ' ');
                continue;
            }
            moveNext = true;
            isEditing = false;
        }
        else if (key == UP || key == DOWN)
        {
            moveNext = (key == DOWN);
            isEditing = false;
        }
        else if (key == '\b' && !result.empty())
        {
            result.pop_back();
        }
        else if (result.length() < maxLength && isValidChar(key))
        {
            result += key;
        }
    }

    ShowCurAtXY(0, 0, false);
    return result;
}

int inputNumber(int x, int y, int current, bool &moveNext)
{
    string result = (current > 0) ? to_string(current) : "";
    char key;
    bool isEditing = true;
    int maxLength = 6;
    string errorMessage;
    while (isEditing)
    {
        displayField(x, y, result, true, maxLength);
        key = getch();

        if (key == ESC)
        {
            moveNext = false;
            return -1;
        }
        if (key == F4)
        {
            moveNext = false;
            return 4;
        }
        if (key == ENTER)
        {
            if (result.empty())
            {
                // gotoxy(x + 30, y);
                errorMessage = "So luong ton khong duoc de trong!";
                drawTableErrors(5, 2, errorMessage);
                // Sleep(1000);
                // gotoxy(x + 30, y);
                // cout << string(50, ' ');
                continue;
            }
            moveNext = true;
            isEditing = false;
        }
        else if (key == UP || key == DOWN)
        {
            moveNext = (key == DOWN);
            isEditing = false;
        }
        else if (key == '\b' && !result.empty())
        {
            result.pop_back();
        }
        else if (result.length() < maxLength && isdigit(key))
        {
            result += key;
        }
    }

    ShowCurAtXY(0, 0, false);
    return result.empty() ? 0 : stoi(result);
}

void nhapVatTu(treeVatTu &root, int x, int y)
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
    string tempInput; // Biến tạm để lưu input trước khi chuẩn hóa

    while (true)
    {
        // Hiển thị tất cả các trường
        displayField(x + 87, y + 4, input.MAVT, currentRow == 0, 10);
        displayField(x + 87, y + 6, input.TENVT, currentRow == 1, 20);
        displayField(x + 87, y + 8, input.DVT, currentRow == 2, 6);
        displayField(x + 87, y + 10, input.soLuongTon > 0 ? to_string(input.soLuongTon) : "", currentRow == 3, 6);

        switch (currentRow)
        {
        case 0:
        {
            // Cho phép nhập mọi ký tự
            result = inputString(x + 87, y + 4, input.MAVT, 10, "Ma vat tu", moveNext);
            if (result == "ESC")
                return;

            // Chuẩn hóa chuỗi sau khi nhập
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ma vat tu chua ky tu khong hop le!";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }

            if (search(root, tempInput) != NULL)
            {
                errorMessage = "Ma vat tu da ton tai!";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            input.MAVT = tempInput;
            formatMAVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
            break;
        }
        case 1:
        {
            // Cho phép nhập mọi ký tự
            result = inputString(x + 87, y + 6, input.TENVT, 20, "Ten vat tu", moveNext);
            if (result == "ESC")
                return;

            // Chuẩn hóa chuỗi sau khi nhập
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Ten vat tu chua ky tu khong hop le!";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            input.TENVT = tempInput;
            formatMAVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
            break;
        }
        case 2:
        {
            // Cho phép nhập mọi ký tự
            result = inputString(x + 87, y + 8, input.DVT, 6, "Don vi tinh", moveNext);
            if (result == "ESC")
                return;

            // Chuẩn hóa chuỗi sau khi nhập
            tempInput = normalizeString(result, hasError);
            if (hasError)
            {
                errorMessage = "Don vi tinh chua ky tu khong hop le!";
                drawTableErrors(5, 2, errorMessage);
                continue;
            }
            input.DVT = tempInput;
            formatMAVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);
            break;
        }
        case 3:
        {
            numResult = inputNumber(x + 87, y + 10, input.soLuongTon, moveNext);
            if (numResult == -1)
                return;
            input.soLuongTon = numResult;
            formatMAVT(input.MAVT, input.TENVT, input.DVT, input.soLuongTon);

            break;
        }
        }
        if (numResult == 4 && result == "F4")
        {
            if (!moveNext && !input.MAVT.empty() && !input.TENVT.empty() &&
                !input.DVT.empty() && input.soLuongTon >= 0)
            {
                root = insert(root, input);
                errorMessage = "Them vat tu thanh cong!";
                drawTableErrors(5, 2, errorMessage);
                Sleep(1000);
                return;
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
// cau b: in va sap xep

int countNodes(treeVatTu root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void storeInorder(treeVatTu root, treeVatTu arr[], int *index)
{
    if (root == NULL)
        return;

    storeInorder(root->left, arr, index);
    arr[*index] = root;
    (*index)++;
    storeInorder(root->right, arr, index);
}

bool compareVatTu(const treeVatTu a, const treeVatTu b)
{
    return a->data_vt.TENVT < b->data_vt.TENVT;
}

int partition(treeVatTu arr[], int low, int high)
{
    treeVatTu pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (compareVatTu(arr[j], pivot))
        {
            i++;
            treeVatTu temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    treeVatTu temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(treeVatTu arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void inDanhSachVatTu(treeVatTu root, int pageNumber, int selectedRow, int x, string &errorMessage)
{
    int n = countNodes(root);
    bool isOpened;
    readFile_dsVatTu(root, isOpened);
    if (n == 0 && isOpened == true)
    {
        errorMessage = "Khong co du lieu vat tu";
        drawTableErrors(5, 2, errorMessage);
        return;
    }
    else if (n == 0 && isOpened == false)
    {
        errorMessage = "Khong the mo file ds_VatTu.txt";
        drawTableErrors(5, 2, errorMessage);
        return;
    }

    treeVatTu *arr = new treeVatTu[n];
    int index = 0;
    storeInorder(root, arr, &index);
    quickSort(arr, 0, n - 1);

    int startIndex = (pageNumber - 1) * ROWS;
    int endIndex = min(startIndex + ROWS, n);

    int currentRow = 5;
    for (int i = startIndex; i < endIndex; i++)
    {
        // MAVT column - với highlight nếu được chọn
        gotoxy(x + 3, currentRow);
        if (selectedRow == -1)
            cout << arr[i]->data_vt.MAVT;
        else if (i - startIndex == selectedRow)
        {
            Highlight(LIGHTBLUE);
            cout << arr[i]->data_vt.MAVT;
            setColorByRequest(LIGHTGRAY,BLACK); // Reset về màu bình thường ngay sau khi in MAVT
        }
        else
        {
            cout << arr[i]->data_vt.MAVT;
        }

        // TENVT column - không highlight
        gotoxy(x + 18, currentRow);
        cout << arr[i]->data_vt.TENVT;

        // DVT column - không highlight
        gotoxy(x + 43, currentRow);
        cout << arr[i]->data_vt.DVT;

        // SoLuongTon column - không highlight
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
// Hàm kiểm tra xem một ký tự có tồn tại trong chuỗi (không phân biệt hoa/thường)
bool hasCharacter(const string &searchStr, const string &targetStr)
{
    if (searchStr.empty() || targetStr.empty())
        return false;

    string searchLower, targetLower;

    // Chuyển cả 2 chuỗi về chữ thường để so sánh
    for (char c : searchStr)
        searchLower += tolower(c);
    for (char c : targetStr)
        targetLower += tolower(c);

    // Kiểm tra từng ký tự
    if (searchStr.length() == 1)
    {
        for (char c : targetLower)
        {
            if (c == searchLower[0])
                return true;
        }
    }
    // Kiểm tra chuỗi con
    else
    {
        int n = targetLower.length();
        int m = searchLower.length();

        for (int i = 0; i <= n - m; i++)
        {
            bool found = true;
            for (int j = 0; j < m; j++)
            {
                if (targetLower[i + j] != searchLower[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
                return true;
        }
    }
    return false;
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

// Sắp xếp kết quả theo tên vật tư
void sortSearchResults(treeVatTu results[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (results[j]->data_vt.TENVT > results[j + 1]->data_vt.TENVT)
            {
                treeVatTu temp = results[j];
                results[j] = results[j + 1];
                results[j + 1] = temp;
            }
        }
    }
}

// Hàm đánh dấu ký tự tìm thấy trong chuỗi
void printHighlightedText(const string &text, const string &searchStr)
{
    if (text.empty() || searchStr.empty())
        return;

    string textLower = text;
    string searchLower = searchStr;

    // Chuyển về chữ thường để so sánh
    for (int i = 0; i < text.length(); i++)
        textLower[i] = tolower(textLower[i]);
    for (int i = 0; i < searchStr.length(); i++)
        searchLower[i] = tolower(searchLower[i]);

    for (int i = 0; i < text.length(); i++)
    {
        bool isMatch = false;
        if (searchStr.length() == 1)
        {
            // Tìm ký tự đơn
            if (textLower[i] == searchLower[0])
            {
                isMatch = true;
            }
        }
        else
        {
            // Tìm chuỗi
            if (i <= textLower.length() - searchLower.length())
            {
                bool found = true;
                for (int j = 0; j < searchLower.length(); j++)
                {
                    if (textLower[i + j] != searchLower[j])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                {
                    isMatch = true;
                }
            }
        }

        if (isMatch)
        {
            SetBGColor(searchHighlightColor); // Đặt nền màu xanh
            if (searchStr.length() == 1)
            {
                cout << text[i];
                SetBGColor(0); // Reset về nền đen
            }
            else
            {
                // In cả chuỗi tìm thấy với nền xanh
                for (int j = 0; j < searchStr.length(); j++)
                {
                    cout << text[i + j];
                }
                i += searchStr.length() - 1;
                SetBGColor(0); // Reset về nền đen
            }
        }
        else
        {
            cout << text[i];
        }
    }
}
// search theo ten
void timKiemVatTu(treeVatTu root)
{
    string searchStr = "";
    bool hasError;
    char ch;

    cout << "Nhap ky tu de tim kiem (ESC de thoat): ";

    while (true)
    {
        // Đọc ký tự từ bàn phím mà không cần nhấn Enter
        ch = _getch();

        // Nếu người dùng nhấn ESC thì thoát
        if (ch == 27)
        {
            cout << "\nDa thoat tim kiem!" << endl;
            break;
        }
        // Xử lý phím Backspace
        else if (ch == 8 && !searchStr.empty())
        {
            searchStr.pop_back();
            // Xóa màn hình phía dưới dòng nhập
            cout << "\033[2K\r"; // Xóa dòng hiện tại
            cout << "Dang tim kiem: " << searchStr;
        }
        // Chỉ xử lý các ký tự in được
        else if (ch >= 32 && ch <= 126)
        {
            searchStr += ch;
            cout << ch;
        }
        else
        {
            continue;
        }

        // Xóa màn hình kết quả cũ
        cout << "\n\033[J"; // Xóa từ vị trí con trỏ đến cuối màn hình

        if (searchStr.empty())
        {
            continue;
        }

        // Chuẩn hóa chuỗi tìm kiếm
        string normalizedStr = normalizeString(searchStr, hasError);

        if (hasError)
        {
            cout << "Du lieu nhap khong hop le!" << endl;
            continue;
        }

        // Đếm số lượng kết quả
        int count = countSearchResults(root, normalizedStr);

        if (count == 0)
        {
            cout << "Khong tim thay vat tu nao co chua '" << searchStr << "' trong ten" << endl;
            continue;
        }

        // Tạo mảng để lưu kết quả
        treeVatTu *results = new treeVatTu[count];
        int index = 0;

        // Lưu các kết quả vào mảng
        storeSearchResults(root, normalizedStr, results, index);

        // Sắp xếp kết quả theo tên
        sortSearchResults(results, count);

        // Hiển thị kết quả
        cout << "\nTim thay " << count << " vat tu co chua '" << searchStr << "' trong ten:" << endl;
        cout << left << setw(15) << "Ma VT"
             << setw(30) << "Ten vat tu"
             << setw(20) << "Don vi tinh"
             << "So luong ton" << endl;
        cout << string(75, '-') << endl;

        for (int i = 0; i < count; i++)
        {
            cout << left << setw(15) << results[i]->data_vt.MAVT;

            // In tên vật tư với highlight
            string tenVT = results[i]->data_vt.TENVT;
            int padding = 30 - tenVT.length();
            printHighlightedText(tenVT, normalizedStr);
            cout << string(padding > 0 ? padding : 0, ' ');

            cout << setw(20) << results[i]->data_vt.DVT
                 << results[i]->data_vt.soLuongTon << endl;
        }

        delete[] results;

        // Di chuyển con trỏ lên đầu dòng nhập
        cout << "\033[F";
    }
}