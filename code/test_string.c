#include <string>
#include <iostream>

using namespace std;
/*
    string 默认初始化为"" 并且与C字符串相比的结尾没有 \0
    字符串的拼接可以直接进行加法操作，不需要担心控件不够会溢出
    strcat、strcpy、malloc

    截取字符串：substr(pos, len): 提取字符串的起始位置和长度
    删除字符串：erase(pos, len): 不指明len的长度，会直接删除从pos到字符串结尾的所有字符
    插入字符串: insert(pos, str): str是要插入的字符串，可以是stting风格的也可以是C风格的
    insert函数的第一个参数有越界的可能性, 如果越界的话，则会产生运行时候的异常 

    字符串查找：find(str, pos = 0): 他会返回子字符串第一次出现在字符串中的起始下标, 如果没有找到的话会返回一个无穷大值
    4294967295
    rfind(str, pos): 和find的不同之处在于，最多查找到第二个参数处，如果到了第二个参数所指定的下标还没有找到就返回一个无穷大值
    4294967295

    find_first_of(str2): 用于查找子字符串和字符串共同具有的字符产在字符串中出现的位置
*/

int main()
{
    string s1("222");
    string s2 = "cpp";
    string s3 = s2;
    string s4 = s1 + s2 + s3;
    cout << s3 << s4 << endl;

    // 转换为c风格的字符串
    string url = "D://HMPP-master-xidian//test.txt";
    FILE *fp = fopen(url.c_str(), "rt");
    if (fp == NULL) {
        puts("faile to open!!!");
        exit(0);
    }

    char str[101];
    // 循环读取每一行数据
    while (fgets(str, 100, fp) != NULL) {
        cout << str;
    }
    // cin 的 运算符 >>  会默认忽略空格，遇到空格旧认为输入结束
    fclose(fp);

    return 0;
}
