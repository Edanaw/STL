## 命名空间
C++将类、函数、宏都放到了一个命名空间中, 这个命名空间的名字就是std -> 标准命名空间

## const常量
和define的区别，一个是在预处理阶段实现替换，一个是在编译阶段进行替换

## 函数重载
参数列表不同: 参数的类型、个数、顺序不同

## 内联函数
inline是一种用于实现的关键字, 不是一种用于声明的关键字。用户没有必要也不应该知道函数是否需要内联。
> 函数可以重复使用，内联函数在编译后就消除了，不存在于虚拟地址空间中，内联函数作为带参数宏替代方案

## this指针
是c++中的一个关键字, 也是一个const指针，指向当前对象，可以通过他访问当前对象的所有成员

## static成员函数static成员变量
static成员变量可以用来在多个对象之间共享, 共享数据的典型场景就是计数
当创建多个对象的时候，也只会为static成员变量分配一份内存, 一般吧static变量设置为public属性
static函数和普通函数的区别是缺少默认的this指针参数, 没有办法访问类的任意成员，只能访问静态成员

## 友元函数
可以使其他类中的成员函数以及全局范围内的函数访问当前类的private成员
> 当前类定义的、不属于当前类的函数也可以在类中声明, 但是要在前面加上friend关键字, 友元函数可以是不属于任何类的

```C++
class student {
    string m_name;
    int m_age;
    float m_score;

public: 
    student(string name, int age, float score);
    friend void show(student *p);
};

student::student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) {}

void show(student *p) {
    cout << p->m_name << " age: " << p->m_age << ", score: " << p->m_score << endl;
}

/*
    show 函数是一个全局范围内的非成员函数，不属于任何的类，他的作用是输出学生的信息
*/ 

int main()
{
    student stu("wang", 12, 123);
    show(&stu);

    student *stu2 = new student("liu", 11, 123);
    show(stu2);
}
```

> 注意：友元函数不同于类的成员函数, 不能直接访问类的长远, 需要借助对象才能访问
