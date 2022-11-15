# -
大一 C语言 课程设计《校园新闻发布管理系统》

从2022年1月1日开始敲下第一行代码，到2022年1月9日完成最后的调试，历时整整九天，《校园新闻发布管理系统》终于诞生了。它具有简洁清晰的菜单，让人一目了然。它能够随时发布、修改、查看、删除新闻，能够随时添加、查看、修改、删除用户账号信息，能够用多种方法搜索各种各样的新闻，也能够统计新闻发布的具体情况。它使用了同步保存的设计，我们不必担心没有正常退出系统而丢失数据；它使用了人性化的操作提示设计，我们用起来更加的舒适和便捷。在完成最低要求的同时，我尽量将它优化得更加人性化，让它更加地友好。
对于我来说，难度一的《校园新闻发布管理系统》无疑是个巨大的挑战。它要求使用结构体链表来储存数据，要求要有文件操作，要求多链表储存新闻数据、用户数据，要求对链表进行增添、删除、排序、搜索等操作，这些对仅仅有C语言基础知识的我们来说无疑是无比巨大的艰难险阻。第一次选择时没有深入学习链表和文件操作，选择了难度一是觉得难度一不是很难，第二次选择时深入了解了链表和文件操作，我依然选择了难度一，是因为我认为在克服困难的同时我能够学到许许多多平时无法学到的东西。设计难度很大，程序十分复杂，而我不懂的东西还有很多。
开始敲下第一行代码后不久，我就遇到了第一个拦路虎。敲着敲着我就迷失了方向，不知道下一步该写哪一部分的代码。对于这个问题，我虚心地请教了师兄。他和我说了一句话，让我至今印象深刻：“如果一艘船不知道该驶去哪个港口，那么任何方向吹来的风都不会是顺风。”他教我，在正式写程序之前，应该先做一个思维导图，把整个系统的框架给勾勒出来，分析他的功能需求，找到它可能需要设计哪一些函数，这样，在写代码的时候，我们就可以根据这个思维导图有目标地去写，而不是像个无头苍蝇一样到处乱撞。即使写着写着卡壳了，我们也可以换一下思路，暂时放下当前的函数，转战另外一个函数，等有思路了再回头来写。
在这九天的时间了，我遇到了不少的大大小小的bug或者编译错误。实话说，编译错误确实很多，不过由于vs会对编译错误进行报错，这类错误到不会使我过于揪心。令人难受的是程序运行中的bug，由于粗心大意造成的如函数声明时漏掉了某个参数，void类型的函数return了一个值，定义指针时没有给其赋值而使用导致程序奔溃，给字符数组赋值时越界导致堆栈损坏，设计函数时逻辑上的错误，数据类型的不统一导致文件操作读写数据成乱码，运行等不到自己的预期结果等等。这一类的错误就只能靠自己不断地debug，不断地查阅资料，不断地和同学讨论，从而找出正确的答案。在这一个过程中，我熟练地掌握了各种debug的方法，比如设置printf查看到底是哪里的语句没有被执行到；巧妙地设置窗口监控变量的值变化，抓住变量脱离正常的那一个瞬间；合理推测哪一部分造成了程序的奔溃，将其注释掉，看看程序下一次还会不会奔溃……我也熟练掌握了各大搜索引擎，可以根据关键词快速地查找出自己想要的答案，我更学会了如何更好地与他人合作，共同解决问题。
没错，在做课设的九天里，我收获最大的就是合作精神。那是一个关于缓冲区的问题。当时我前后混合使用了scanf函数和gets函数，运行时发现我还没有输入，gets语句就被跳过了，而且还真取到了值。一开始我对缓冲区理解不深，上网查了一下，网友介绍了一个发fflush（）函数，我使用了一下发现没有起到作用。思考了很久，我无法解决问题，于是我询问了2班的万博弈同学，他和我详细介绍了缓冲区的知识，引导我用getchar（）函数设计了一个循环来清空缓冲区，随后，我们还认识一个rewind（stdin）函数，更加简洁有效。在此次讨论后，我认识到键盘输入也相当于文件，而缓冲区的清理也有着多种办法。还有就是我的舍友肖烁豪同学，九天里，我每天和他一同前往图书馆编写程序，休息时间和他一起讨论设计中遇到的问题。许多时候，在遇到困难时，每当我们其中一人想要放弃，我们都会互相鼓励着对方，互相打着气，由此，我们也不惧怕任何困难。这让我想起了一句话：一个人可以走得很快，但一群人才可以走得很远。在与同学们的陪伴下，我们一定可以走得越来越远。
这九天的课设时间，我反反复复地翻书，把之前漏掉的许多知识点捡了回来；我也学多了许多书本上学不到的东西，比如说rewind（stdin）函数、strncat（）函数和strstr（）函数，帮我解决了几个难以解决的问题。课设很难，但是也很有趣，只要你积极乐观地面对他，困难总会变成乐趣。课设改了又改，优化了再优化，很累，但是看到自己真正优化到了点上时，自己又很开心，很有成就感。优化是永远也优化不完的，繁杂的代码可以更加简洁，增加的功能可以有更多，系统的运行可以更加有逻辑……我很感激谢老师教给我们的不断优化的思想，精益求精的精神；我很感激谢老师教给我们的不惧困难、耐心应对挑战的品格；我更感激谢老师教给我们的合作的精神，让我们不论合适都有应对挑战的勇气与毅力。知识固然能够开阔人的视野，但是精神的升华更能促进人的成长。在课设之后，还有更大的挑战等着我们，我们当以一往无前的魄力，积极乐观的心态迎接未来的每一个挑战！
