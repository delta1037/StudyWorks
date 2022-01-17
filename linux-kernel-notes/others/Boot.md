# Linux启动过程分析

## 第一阶段-BIOS

计算机通电后，首先会区读取ROM芯片中的开机程序（基本输入输出系统/BIOS）

### 1.1 硬件自检

BIOS程序首先检查计算机硬件是否满足运行的基本条件--**硬件自检**（POST）

CMOS：存储硬件的各项参数。

### 1.2 启动顺序

硬件自检完成后，BIOS把控制权交给下一阶段的启动程序。

这时，BIOS需要知道下一阶段的启动程序在哪个设备，也就是BIOS需要有一个外部存储设备排序，排在前边的设备就是优先转交控制权的设备。这个排序叫**启动顺序**。

## 第二阶段-主引导记录

BIOS把控制权交给排在第一位的存储设备。

计算机读取此设备的第一个扇区（最前边的512个字节，叫做**主引导记录**<Master boot record，缩写为**MBR**>），如果这个扇区最后两个字节是0x55和0xAA，表明设备可以启动；如果不是，表明设备不能启动，控制权交给启动顺序中的下一个 设备。

### 2.1 主引导记录结构

| 范围/字节 | 作用                       |
| --------- | -------------------------- |
| 1-446     | 调用操作系统的机器码       |
| 447-510   | 分区表：将磁盘分为若干个区 |
| 511-512   | 主引导记录签名             |

### 2.2 分区表

考虑到每个区可以安装不同的操作系统，主引导记录必须知道将控制权交给哪个区。

分区表长度有64个字节，里面分为四项（所以一个硬盘最多有四个一级分区，又叫主分区），每一项16个字节

主分区16个字节组成：

| 范围/字节 | 作用                                                         |
| --------- | ------------------------------------------------------------ |
| 1-1       | 如果为0x80，就表示该分区是激活分区，控制权要交给这个分区。四个分区里面只能有一个是激活的 |
| 2-4       | 主分区第一个扇区的物理位置（柱面、磁头、扇区号）             |
| 5-5       | 主分区类型                                                   |
| 6-8       | 主分区最后一个扇区的物理位置                                 |
| 9-12      | 该主分区第一个扇区的逻辑地址                                 |
| 13-16     | 主分区的扇区总数                                             |

## 第三阶段-硬盘启动

这时，计算机的控制权就交给了硬盘的某个分区了

### 3.1 情况A：卷引导记录

计算机会读取激活分区的第一个扇区，叫做卷引导记录（Volume boot record，VBR）

卷引导记录告诉计算机，操作系统在这个分区的位置。然后计算机就会加载操作系统了。

### 3.2 情况B：扩展分区和逻辑分区

随着硬盘越来越大，四个分区已经不够了，需要更多分区。于是规定有一个分区可以定义为扩展分区（里面又分了好多个区，叫逻辑分区）。

计算机首先读取扩展分区的第一个扇区，叫扩展引导记录（EBR）。它里面包含一张64字节的分区表，但是最多只有两项（也就是两个逻辑分区，包括它自身的分区表和下一个分区的分区表）。从里面找到第二个逻辑分区的位置，直到找到一个分区里面只包含它自己的分区表为止。

### 3.3 情况C：启动管理器

在这种情况下，计算机读取主引导记录前446个字节的机器码之后，不把控制权交给某一个分区，而是运行启动管理器（boot loader），由用户选择启动哪一个操作系统。

Linux环境中，最流行的启动管理器是Grub。

## 第四阶段-操作系统

控制权交给操作系统之后，操作系统的内核首先载入内存。

所有进程的祖先叫进程0，idle进程，或者由于历史的原因叫做swapper进程。

start_kernel()函数初始化内核需要的所有数据结构，激活终端，创建另一个叫做进程1的内核线程（一般叫做init进程），创建init进程之后，进程0执行cpu_idle()函数，该函数本质上是在开中断的情况下重复之星hlt汇编指令。当 没有其他进程处于TASK_RUNNING才选择执行进程0。

**多处理器系统**中每个CPU都有一个进程0，计算机启动之后首先启动一个CPU，禁用其他CPU，swapper进程进程初始化内核数据结构，通过copy_process()函数创建另外的swapper进程。

进程0创建的内核线程执行init()函数，init()依次完成内核初始化。init()调用execve()系统调用装入可执行程序init，结果init内核线程变成了一个普通进程。

以Linux系统为例，首先载入/boot目录下面的kernel。内核加载成功后（如上），第一个运行的程序是/sbin/init，它根据配置文件产生init进程，pid进程编号为1，其它进程都是它的后代。

然后init进程加载系统的各个模块，比如窗口和网络程序，直到/bin/login程序，跳出登录页面。

## 参考文献

1.  [计算机是如何启动的](http://www.ruanyifeng.com/blog/2013/02/booting.html)
2.  深入理解Linux内核
