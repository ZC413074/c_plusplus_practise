## [Openmp(Open Multi-Processing)](https://www.openmp.org/specifications/)
---
### 一、OpenMP概述
#### 1. 用途
&emsp;&emsp;显式直到多线程、共享内存的并行性，支持C、C++和Fortran编程语言，支持Sun Compiler、GNU Compiler和Intel Compiler编译器，支持Unix/Linux和Windows平台，有以下功能：
* 产生平行区域
* 在线程之间划分代码块
* 在线程之间分配循环迭代
* 序列化代码段
* 线程之间的工作同步
#### 2. 组成
主要分为以下三部分：  
* 编译指令(19)
* 运行时库程序(32)
* 环境变量(9)
#### 3. 优缺点

<br>
### 二、工程属性配置及OpenMP使用
#### 1. 工程属性配置
* CMake 3.9 and 3.9+  
```
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(MyTarget PUBLIC OpenMP::OpenMP_CXX)
endif()
```
* CMake 3.9-
```
if(NOT TARGET OpenMP::OpenMP_CXX)
    find_package(Threads REQUIRED)
    add_library(OpenMP::OpenMP_CXX IMPORTED INTERFACE)
    set_property(TARGET OpenMP::OpenMP_CXX
                 PROPERTY INTERFACE_COMPILE_OPTIONS ${OpenMP_CXX_FLAGS})
    # Only works if the same flag is passed to the linker; use CMake 3.9+ otherwise (Intel, AppleClang)
    set_property(TARGET OpenMP::OpenMP_CXX
                 PROPERTY INTERFACE_LINK_LIBRARIES ${OpenMP_CXX_FLAGS} Threads::Threads)
endif()
target_link_libraries(MyTarget PUBLIC OpenMP::OpenMP_CXX)
# Warning: CMake < 3.4 has a bug in the Threads package that requires you to have the C language enabled.
```
* vs属性->C/C++->语言-OpenMP支持
#### 2.OpenMP简单使用
```
#include<iostream>
#include<omp.h>
#include<ctime>
#define random(a,b) (rand()%(b-a)+a)
void opemp_test()
{
	int n = 10000;
	double c;
	double a = 7;
	srand((int)time(0));
	int m = 10;
	int time = 0;
	while (m)
	{
		std::clock_t start = std::clock();
		//omp_set_num_threads(8);
#pragma omp parallel  for
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				random(5, 10);
			}
		}
		std::clock_t end = std::clock();
		time += end - start;
		std::cout << " time:" << end - start << " ms" << std::endl;
		--m;
	}

	std::cout << "average time:" << time / 10 << " ms" << std::endl;
}
int main()
{
    opemp_test();
    return 0;
}
``` 
<br>
### 三、OpenMP的指令
基本语句如下    
```
#pragma omp directivee [clause[[,]clause ]...]
```
* 区分大小写
* 每个指令只能指定一个指令名
* 每个指令最多使用一个后续语句，该语句必须式结构化块
* 通过在指令末尾用反斜杠("\")，可以在后续上继续长指令
####  1. directive
| 指令 | 含义 |
| :----: | :----: |
| atomic  | 内存位置将会原子更新 |
| barrier  | 线程在此等待，直到所有的线程都运行到此barrier。用来同步所有线程 |
| critical   | 其后的代码块为临界区，任意时刻只能被一个线程运行 |
| flush   | 所有线程对所有共享对象具有相同的内存视图 |
| for   |  用在for循环之前，把for循环并行化由多个线程执行。循环变量只能是整型 |
| master   | 指定由主线程来运行接下来的程序 |
| ordered   | 指定在接下来的代码块中，被并行化的 for循环将依序运行 |
| parallel   | 代表接下来的代码块将被多个线程并行各执行一遍 |
| sections   | 将接下来的代码块包含将被并行执行的section块 |
| single   | 之后的程序将只会在一个线程（未必是主线程）中被执行，不会被并行执行 |
| threadprivate   | 指定一个变量是线程局部存储 |

####  2. clause
| 指令 | 含义 |
| :----: | :----: | 
| copyin   | 让threadprivate的变量的值和主线程的值相同 | 
| copyprivate    | 不同线程中的变量在所有线程中共享 | 
| default    | 让threadprivate的变量的值和主线程的值相同 | 
| firstprivate    | 对于线程局部存储的变量，其初值是进入并行区之前的值 | 
| if   | 判断条件，可用来决定是否要并行化 | 
| lastprivate    |  在一个循环并行执行结束后，指定变量的值为循环体在顺序最后一次执行时获取的值，或者#pragma sections在中，按文本顺序最后一个section中执行获取的值 | 
| nowait      | 忽略barrier的同步等待 |
| num_threads     | 设置线程数量的数量。默认值为当前计算机硬件支持的最大并发数。一般就是CPU的内核数目。超线程被操作系统视为独立的CPU内核 | 
| ordered    | 使用于 for，可以在将循环并行化的时候，将程序中有标记 directive ordered 的部分依序运行 | 
| private    | 指定变量为线程局部存储 | 
| reduction    | 让threadprivate的变量的值和主线程的值相同 | 
| schedule    | 设置for循环的并行化方法：dynamic、guided、runtime、static 四种方法 | 
| shared    | 指定变量为所有线程共享 | 


clause包括：
shared，线程间数据共享，每个线程都可以自由的读取和修改数值，如果存在写操作，必须对共享变量加以保护       ；尽量将共享变量的访问转化为私有变量的访问；
private，线程内数据私有，不收其他线程数据的影响，每个线程内都有自己的私有副本，声明在循环结构区域       内的自动变量都是私有的；
default，指定并行域内的变量的使用方式，如default（shared），则并行域内所有的未声明的量就是shared；
nowait，可以忽略其他制导指令暗含的路障；
schedule，针对循环结构，有static,dynamic,guided,runtime四种模式，手册上说static的效率最高；
ordered，使不同线程上的输出数据有序；
if，判断是否值得进行并行；

PS：默认情况下C++最外层并行for循环的索引变量是是私有的，但在嵌套的并行for循环里是共享的。当存在循环嵌套的时候，你经常希望内部循环的索引变量是私有的，那就需要用private子句来指定这些变量。

### 参考链接
1. [cmake官网文档](https://cmake.org/cmake/help/latest/index.html)
2. [modern cmake 添加openmp](https://cliutils.gitlab.io/modern-cmake/chapters/features/cpp11.html)
3. [more modern cmake](https://www.bilibili.com/video/av668434690)
4. [Microsoft OpenMP指令](https://docs.microsoft.com/zh-cn/cpp/parallel/parallel-programming-in-visual-cpp?view=msvc-160)
5. [OpenMP Tutorial 详细](https://hpc.llnl.gov/openmp-tutorial#Introduction)
6. [OpenMP课代表笔记](https://www.cnblogs.com/lfri/p/10111315.html)
7. [OpenMP并行开发C++](https://zhuanlan.zhihu.com/p/51173703)
8. [OpenMP任务调度](https://blog.csdn.net/billbliss/article/details/44131919)
<br/>
## TBB
---
<br/>
## Cuda
---
<br/>