#pragma once
#include "../screens/doHoa.h"
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
//
void displayField(int x, int y, const string &value, bool isActive, int maxLength)
{
    SetBGColor(BLACK);
    SetColor(WHITE);

    gotoxy(x + 1, y);
    cout << string(maxLength, ' ');
    gotoxy(x + 1, y);
    cout << value;

    if (isActive)
    {
        ShowCurAtXY(x + 1 + value.length(), y, true);
    }
    SetBGColor(BLACK);
    SetColor(WHITE);
}

string inputString(int x, int y, string current, int maxLength, string fieldName, bool &moveNext, bool isSmallErrorTable)
{
    string currentInput = current;
    int cursorPos = current.length();
    bool isEditing = true;
    string errorMessage;
    int xTable = 5;
    int yTable = 2;
    while (isEditing)
    {
        setColorByRequest(BLACK, WHITE);
        gotoxy(x + 1, y);
        cout << string(maxLength, ' ');
        gotoxy(x + 1, y);
        cout << currentInput;
        gotoxy(x + 1 + cursorPos, y);
        int key = _getch();
        if (key == 224 || key == 0)
        {
            key = _getch();
            switch (key)
            {
            case UP:
                moveNext = false;
                isEditing = false;
                break;
            case DOWN:
                moveNext = true;
                isEditing = false;
                break;
            case LEFT:
                if (cursorPos > 0)
                    cursorPos--;
                break;
            case RIGHT:
                if (cursorPos < currentInput.length())
                    cursorPos++;
                break;
            case HOME:
                cursorPos = 0;
                break;
            case END:
                cursorPos = currentInput.length();
                break;
            case DEL:
                if (cursorPos < currentInput.length())
                {
                    currentInput.erase(cursorPos, 1);
                }
                break;
            case F10:
                moveNext = false;
                return "F10";
            }
            continue;
        }
        else
        {
            switch (key)
            {
            case ESC:
                moveNext = false;
                return "ESC";
            case ENTER:
                if (currentInput.empty())
                {
                    errorMessage = fieldName + " khong duoc de trong!";
                    drawTableErrors(errorMessage, isSmallErrorTable);
                    continue;
                }
                moveNext = true;
                isEditing = false;
                break;
            case BACKSPACE:
                if (cursorPos > 0)
                {
                    currentInput.erase(cursorPos - 1, 1);
                    cursorPos--;
                }
                break;
            default:
                if (currentInput.length() < maxLength && isValidChar(key))
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
                }
            }
        }
        drawTableErrors("", isSmallErrorTable);
    }
    ShowCurAtXY(0, 0, false);
    return currentInput;
}

int inputNumber(int x, int y, int current, int maxLength, string fieldName, bool &moveNext, bool isSmallErrorTable)
{
    string currentInput = (current > 0) ? to_string(current) : "";
    int cursorPos = currentInput.length();
    bool isEditing = true;
    string errorMessage;
    int xTable = 5;
    int yTable = 2;
    while (isEditing)
    {
        setColorByRequest(BLACK, WHITE);
        gotoxy(x + 1, y);
        cout << string(maxLength, ' ');
        gotoxy(x + 1, y);
        cout << currentInput;
        gotoxy(x + cursorPos + 1, y);

        int key = _getch();
        if (key == 224 || key == 0)
        {
            key = _getch();
            switch (key)
            {
            case UP:
                moveNext = false;
                isEditing = false;
                break;
            case DOWN:
                moveNext = true;
                isEditing = false;
                break;
            case LEFT:
                if (cursorPos > 0)
                    cursorPos--;
                break;
            case RIGHT:
                if (cursorPos < currentInput.length())
                    cursorPos++;
                break;
            case HOME:
                cursorPos = 0;
                break;
            case END:
                cursorPos = currentInput.length();
                break;
            case DEL:
                if (cursorPos < currentInput.length())
                {
                    currentInput.erase(cursorPos, 1);
                }
                break;
            case F10:
                moveNext = false;
                return -10;
            }
            continue;
        }
        switch (key)
        {
        case ESC:
            moveNext = false;
            return -1;
        case ENTER:
            if (currentInput.empty())
            {
                errorMessage = fieldName + " khong duoc de trong!";
                drawTableErrors(errorMessage, isSmallErrorTable);
                continue;
            }
            moveNext = true;
            isEditing = false;
            break;
        case BACKSPACE:
            if (cursorPos > 0)
            {
                currentInput.erase(cursorPos - 1, 1);
                cursorPos--;
            }
            break;
        default:
            if (currentInput.length() < maxLength && isdigit(key))
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
            }
        }
        drawTableErrors("", isSmallErrorTable);
    }
    ShowCurAtXY(0, 0, false);
    return currentInput.empty() ? 0 : stoi(currentInput);
}

void formatInputVT(string &MAVT, string &TENVT, string &DVT, int &SLT)
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
    if (SLT < 0)
    {
        SLT = 0;
    }
}

void formatInputNV(string &MANV, string &HO, string &TEN, string &PHAI)
{
    if (MANV.length() > 10)
    {
        MANV = MANV.substr(0, 10);
    }
    if (HO.length() > 20)
    {
        HO = HO.substr(0, 20);
    }
    if (TEN.length() > 6)
    {
        TEN = TEN.substr(0, 6);
    }
    if (PHAI.length() > 6)
    {
        PHAI = PHAI.substr(0, 6);
    }
}
void formatInputHD(string &SoHD, string &day, string &month, string &year,string &loai)
{
    if (SoHD.length() > 20)
    {
        SoHD = SoHD.substr(0, 20);
    }
    if (day.length() > 2)
    {
        day = day.substr(0, 2);
    }
    if (month.length() > 2)
    {
        month = month.substr(0, 2);
    }
    if (year.length() > 4)
    {
        year = year.substr(0, 4);
    }
    if (loai.length() > 1)
    {
        loai = loai.substr(0, 1);
    }
}
void formatInputCTHD(string &MAVT, string &soLuong, string &donGia, string &VAT)
{
    if (MAVT.length() > 10)
    {
        MAVT = MAVT.substr(0, 10);
    }
    if (soLuong.length() > 6)
    {
        soLuong = soLuong.substr(0, 6);
    }
    if (donGia.length() > 9)
    {
        donGia = donGia.substr(0, 9);
    }
    if (VAT.length() > 3)
    {
        VAT = VAT.substr(0, 3);
    }
}
int partitionDoanhThu(doanhThuVatTu arr[], int low, int high)
{
    float pivot = arr[high].doanhThu;
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j].doanhThu > pivot)
        {
            i++;
            doanhThuVatTu temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    doanhThuVatTu temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSortDoanhThu(doanhThuVatTu arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionDoanhThu(arr, low, high);
        quickSortDoanhThu(arr, low, pi - 1);
        quickSortDoanhThu(arr, pi + 1, high);
    }
}

int partitionVatTu(treeVatTu arr[], int low, int high)
{
    treeVatTu pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j]->data_vt.TENVT < pivot->data_vt.TENVT)
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

void quickSortVatTu(treeVatTu arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionVatTu(arr, low, high);
        quickSortVatTu(arr, low, pi - 1);
        quickSortVatTu(arr, pi + 1, high);
    }
}

bool isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    if (year % 400 == 0)
        return true;
    return false;
}

bool isValidTime(int day, int month, int year)
{
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || month < 1 || month > 12)
        return false;
    if (isLeapYear(year) && month == 2)
    {
        if (day <= 29 && day > 0)
            return true;
        return false;
    }
    if (day > 0 && day <= days_in_month[month - 1])
        return true;
    return false;
}

bool timeConflict(int day1, int month1, int year1, int day2, int month2, int year2)
{
    if (year1 > year2)
        return true;
    if (year1 == year2)
    {
        if (month1 > month2)
            return true;
        if (month1 == month2)
        {
            if (day1 > day2)
                return true;
            else
                return false;
        }
    }
    return false;
}
void layNgayThangNam(int &ngay, int &thang, int &nam)
{
    time_t t = time(nullptr);
    tm *now = localtime(&t);

    ngay = now->tm_mday;
    thang = now->tm_mon + 1;   // Tháng bắt đầu từ 0 nên cần cộng 1
    nam = now->tm_year + 1900; // Năm tính từ 1900 nên cộng thêm 1900
}

string formatMoney(int amount)
{
    stringstream ss;

    if (amount < 1000)
    {
        ss << amount;
    }
    else
    {
        int billions = amount / 1000000000;
        int millions = (amount / 1000000) % 1000;
        int thousands = (amount / 1000) % 1000;
        int hundreds = amount % 1000;

        if (billions > 0)
        {
            ss << billions << "." << setw(3) << setfill('0') << millions << "." << setw(3) << setfill('0') << thousands << "." << setw(3) << setfill('0') << hundreds;
        }
        else if (millions > 0)
        {
            ss << millions << "." << setw(3) << setfill('0') << thousands << "." << setw(3) << setfill('0') << hundreds;
        }
        else if (thousands > 0)
        {
            ss << thousands << "." << setw(3) << setfill('0') << hundreds;
        }
        else
        {
            ss << hundreds;
        }
    }
    return ss.str();
}