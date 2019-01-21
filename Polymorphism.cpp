// 多型
// 一個訊息（message or event or stimulus）的意義是由接收者（接收到這個訊息的物件）來解釋，而不是由訊息發出者（sender）來解釋。
// 所以，在runtime時只要接受者換成不同的物件或是instance，系統的行為就會改變。具有這樣的特性就稱之為polymorphism。

#include <iostream>

using namespace std;

class Father{
public:
    virtual void show() { // 如果把這個virtual拿掉，就無法Dynamic binding了
        cout << "it's Father" << endl;
    }
};

class Son : public Father{
public:
    virtual void show() {
        cout << "it's Son" << endl;
    }
};

void showByPtr(Father *father) {
    father->show();
}

void showByRef(Father &father) {
    father.show();
}

int main() {
    Father father;
    Son son;
    Father *pFather = &son;

    // Dynamic binding，在執行時期才決定member function是執行Father還是Son的。
    showByPtr(&father);
    showByPtr(&son);
    showByPtr(pFather);
    showByRef(father);
    showByRef(son);

    // Static binding，在編譯時期就決定member function是執行Father還是Son的。
    father.show();
    son.show();

    return 0;
}
