#pragma once
#include "../libraries/khaibao.h"
#include "../libraries/mylib.h"
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

bool checkMAVT(treeVatTu root, const string &MAVT)
{
    if (root == NULL)
        return false;

    if (root->data_vt.MAVT == MAVT)
        return true;

    if (MAVT < root->data_vt.MAVT)
        return checkMAVT(root->left, MAVT);

    return checkMAVT(root->right, MAVT);
}

string formatMAVT(string MAVT)
{
    if (MAVT.length() > 10)
    {
        MAVT = MAVT.substr(0, 10);
        cout << "Ma vat tu da duoc cat bot xuong 10 ky tu thanh: " << MAVT << endl;
    }
    return MAVT;
}

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
        cout << "Loi: Chuoi khong duoc rong hoac chi chua khoang trang!\n";
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
void readFile_dsVatTu(treeVatTu &root)
{
    bool hasError;
    ifstream filein;
    filein.open(filePath_VT, ios_base::in);
    if (!filein.is_open())
    {
        cout << "Khong the mo file ds_VatTu.txt" << endl;
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

void nhapVatTu(treeVatTu &root)
{
    nodeVatTu data_vt;
    string MAVT, tenVT, dvt;
    bool isValidMAVT = false;
    bool hasError;

    // Nhập và kiểm tra MAVT
    do
    {
        cout << "Nhap ma VT: ";
        getline(cin, MAVT);

        MAVT = formatMAVT(MAVT);

        if (checkMAVT(root, MAVT))
        {
            cout << "Loi: Ma vat tu '" << MAVT << "' da ton tai trong he thong!\n";
            cout << "Vui long nhap ma vat tu khac.\n";
            isValidMAVT = false;
        }
        else
        {
            data_vt.MAVT = MAVT;
            isValidMAVT = true;
        }
    } while (!isValidMAVT);

    // Nhập và chuẩn hóa tên vật tư
    do
    {
        cout << "Nhap ten vat tu: ";
        getline(cin, tenVT);
        tenVT = normalizeString(tenVT, hasError);
        if (!hasError && tenVT.empty())
        {
            cout << "Loi: Ten vat tu khong duoc de trong!\n";
            hasError = true;
        }
    } while (hasError);
    data_vt.TENVT = tenVT;

    // Nhập và chuẩn hóa đơn vị tính
    do
    {
        cout << "Nhap don vi tinh: ";
        getline(cin, dvt);
        dvt = normalizeString(dvt, hasError);
        if (!hasError && dvt.empty())
        {
            cout << "Loi: Don vi tinh khong duoc de trong!\n";
            hasError = true;
        }
    } while (hasError);
    data_vt.DVT = dvt;

    cout << "Nhap so luong ton: ";
    cin >> data_vt.soLuongTon;
    cin.ignore();

    root = insert(root, data_vt);
    writeFile_dsVatTu(root);
    cout << "Da them vat tu thanh cong!\n";
    cout << "Thong tin sau khi chuan hoa:\n";
    cout << "Ten vat tu: " << data_vt.TENVT << endl;
    cout << "Don vi tinh: " << data_vt.DVT << endl;
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

void inDanhSachVatTu(treeVatTu root)
{
    int n = countNodes(root);
    treeVatTu *arr = new treeVatTu[n];
    int index = 0;

    storeInorder(root, arr, &index);
    quickSort(arr, 0, n - 1); // Thay bubbleSort bằng quickSort

    cout << left << setw(15) << "Ma VT"
         << setw(30) << "Ten vat tu"
         << setw(20) << "Don vi tinh"
         << "So luong ton" << endl;
    cout << string(75, '-') << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(15) << arr[i]->data_vt.MAVT
             << setw(30) << arr[i]->data_vt.TENVT
             << setw(20) << arr[i]->data_vt.DVT
             << arr[i]->data_vt.soLuongTon << endl;
    }

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
// Hàm tìm kiếm và hiển thị kết quả
void timKiemVatTu(treeVatTu root)
{
    string searchStr;
    bool hasError;

    cout << "Nhap ky tu hoac chuoi can tim trong ten vat tu: ";
    getline(cin, searchStr);

    if (searchStr.empty())
    {
        cout << "Vui long nhap it nhat mot ky tu!" << endl;
        return;
    }

    // Chuẩn hóa chuỗi tìm kiếm
    searchStr = normalizeString(searchStr, hasError);

    if (hasError)
    {
        cout << "Du lieu nhap khong hop le!" << endl;
        return;
    }

    // Đếm số lượng kết quả
    int count = countSearchResults(root, searchStr);

    if (count == 0)
    {
        cout << "Khong tim thay vat tu nao co chua '" << searchStr << "' trong ten" << endl;
        return;
    }

    // Tạo mảng để lưu kết quả
    treeVatTu *results = new treeVatTu[count];
    int index = 0;

    // Lưu các kết quả vào mảng
    storeSearchResults(root, searchStr, results, index);

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
        printHighlightedText(tenVT, searchStr);
        cout << string(padding > 0 ? padding : 0, ' '); // Thêm khoảng trắng để đảm bảo căn lề

        cout << setw(20) << results[i]->data_vt.DVT
             << results[i]->data_vt.soLuongTon << endl;
    }

    delete[] results;
}