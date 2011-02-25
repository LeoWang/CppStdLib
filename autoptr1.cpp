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
    auto_ptr<int> p(new int(42));
    auto_ptr<int> q;

    cout<<"after initialization:"<<endl;
    cout<<"p:"<<p<<endl;
    cout<<"q:"<<q<<endl;

    q = p;
    cout<<"after assigning auto pointers:"<<endl;
    cout<<"p:"<<p<<endl;
    cout<<"q:"<<q<<endl;

    *q += 13;           //change value of the object q owns
    p = q;
    cout<<"p:"<<p<<endl;
    cout<<"q:"<<q<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
