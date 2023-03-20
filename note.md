# 程序编写细节处理

## 文件命名

- VS创建解决方案时命名为cpphomeworkweek*/chomeworkweek*
- 项目名称应为能够准确描述程序内容的中文
- 源文件名为提交时的要求

## debug规范

- dev中用32debug
- vs中用x86debug
- 右键solution选择设置启动项目,选择current selection

## 编程规范

- 一个语句一行
- 变量名不要用中文
- 不要使用全文替换
- 推荐使用常变量而不是符号变量
- 禁用goto语句
- 文件开头应该有姓名学号班级(应该已经包含在模板中)
- c源文件最开始要加`#define _CRT_SECURE_NO_WARNINGS`
- 最后一个有效输出最后要加换行
- 输出为浮点数的且未指定格式的，均要求 `double` 型，C++为 cout 缺省输出，C 为`%lf` 的缺省输出

推荐格式

``` c++
#include <iostream> 
#include <cmath> //数学函数对应头文件，VS可省略 
using namespace std; 
int main() 
{	
    double a = 0, b = 5.78 * 3.5, c = 2 * sin(2.0);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}
```

- 条件和顺序语句中()后跟{接着换行继续写,要有对应缩进
- 条件和顺序语句中的语句序列中只有一个语句时必须要在()下一行写,即使是空语句
- ctrl+K按住K不动再按F可以排版所选代码
- 对于实型变量,在判断是否相等时不要用==,而是应该相减的绝对值小于一个误差值

### 头文件

- vs中使用sin等数学公式时不需要cmath的头文件,但是如果要使用的话一定要加上去
- C方式（源程序后缀为.c）加 `#include <stdbool.h>`后， 也可使用`bool`/`true`/`false`

## cpp源文件转换为c源文件

### 输入

- 把`cin >>`替换为`scanf(`
- 输入带符号的整数用`%d`
- 输入double型用`%lf`
- 有些时候vs会自动在%前后添加空格,须删去

### 输出

- 把`cout >>`转换为`printf("`
- 把`>> endl`转换为`\n")`
- 输出为浮点数的且未指定格式时,用`%lf`

### 其他

- c中的类型转换格式为`(int)(expression)`
