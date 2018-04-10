## 实验和测试
除了UCT，Pachi 提供一个简单的低级引擎和一个空的蒙特卡洛树作为例子，这个蒙特卡洛树模拟（快速落子）策略都支持可拔插。默认情况下我们使用大量领域知识。

其他特殊引擎同样提供：

- 用于集群运行的“分布式”引擎，分布式的用户端应该提供所有指导
- 一个基本的“悔棋”引擎会通过快速落子策略的建议简单的执行下一步。
- 一个基本的“模板”引擎会根据以学的的模板落子
- 其他一小部分纯粹为开发而用

Pachi 可以作为一个测试对象来开发其他围棋对战平台。例如，想对战“plainest UCT”选手，需要以下命令：

`./pachi -t =5000 policy=ucb1,playout=light,prior=eqex=0,dynkomi=none,pondering=0,pass_all_alive`


这条命令会固定每次落子的时间为5000，生成节点的选择策略从 ucb1amaf到ucb1 （既，关闭了RAVE），生成落子的选择策略从heuristic-heavy moggy t到 uniformly random light，试探性的结束高于价值的节点，关闭动态贴目，在对手时间禁用思考并且保证Pachi 只有10%的活棋留在棋盘上（以避免计子争端）。

但是请注意，在这种模式下使用Pachi 并没有进行广泛的测试，所以在使用它之前，请检查它的性能。

请注意，即使在“基础UCT”模式下，Pachi也会根据初始状态下棋盘的对称性来优化搜索树。目前，还没有任何一种简单的操作能够关闭这一功能。有一个简单的方法是通过更改客户端的棋盘下的board_symmetry_update()使其在开始时转向(goto)break_symmetry和 ，和board_clear然后从新设置默认值board->symmetry.type = SYM_NONE.