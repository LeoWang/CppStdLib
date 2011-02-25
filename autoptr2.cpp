#include <cstdlib>
#include <memory>
#include <iostream>

using std::auto_ptr;
using std::ostream;
using std::cout;
using std::endl;

/* define output operator for auto_ptr
* print object value or NULL
*/
template <typename T>
ostream& operator<< (ostream& strm, const auto_ptr<T>& p)
{
    // does p own an object ?
    if(p.get() == NULL){
         strm<<"NULL";
    }
    else{
         strm<< *p;
    }
    return strm;
}

int main(int argc, char *argv[])
{
    const auto_ptr<int> p(new int(42));
    const auto_ptr<int> q(new int(0));
    const auto_ptr<int> r;

    cout<<"after initialization:"<<endl;
    cout<<"p:"<<p<<endl;
    cout<<"q:"<<q<<endl;
    cout<<"r:"<<r<<endl;

    *q = *p;
    //*r = *p;          运行时错误，指针r未定义，无法使用 
    *p = -77;
    cout<<"after assigning values:"<<endl;
    cout<<"p:"<<p<<endl;
    cout<<"q:"<<q<<endl;
    cout<<"r:"<<r<<endl;

    //q=p;              const修饰的auto_ptr无法移交拥有权 
    //r = p;

    system("PAUSE");
    return EXIT_SUCCESS;
}
