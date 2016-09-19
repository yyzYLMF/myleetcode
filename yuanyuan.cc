#include <iostream>
using namespace std;


//模板类
template <typename T,int num>
class Queue
{
private:
        T arr[num];
        int front;
        int rear;
public:
        Queue() //构造函数
        {
         front=0;
         rear=0;
        }

        bool isEmpty();//判断队列是否为空
        bool isFull();//判断队列是否为满
        bool push(const T &);//进队列
        bool pop(T &);//出队列 这里的参数一定是引用 因为要改变其本身
};

template <typename T,int  num>
bool Queue<T,num>::isEmpty()
{
        return front==rear;
}

template<typename T,int num>
bool Queue<T,num>::isFull()
{
        return front==num;
}

template<typename T,int num> //进队列 判断队列是否满
bool Queue<T,num>::push(const T &a)
{
        if(isFull())
        {
         cout<<"队列已满"<<endl;
         return false;
        }
        else
        {
         arr[front]=a;
         ++front;
        }
        return true;
}

template<typename T,int num>
bool Queue<T,num>::pop(T &b)
{
        if(isEmpty())
        {
         cout<<"队列空了"<<endl;
         return false;
        }
        else
        {
         b=arr[rear];
         ++rear;
        }
        return true;
}

int main()
{
        Queue<int,7> q;  //开7个空间
        cout<<"刚开始队列空吗?  "<<q.isEmpty()<<endl;
        q.push(6);
        q.push(10);
        cout<<"现在还是队列空吗?  "<<q.isFull()<<endl;
        int b1,b2;
        q.pop(b1);
        q.pop(b2);
        cout<<"队列中第一个删除的元素为:  "<<b1<<endl;
        cout<<"队列中第二个删除的元素为:  "<<b2<<endl;
}
