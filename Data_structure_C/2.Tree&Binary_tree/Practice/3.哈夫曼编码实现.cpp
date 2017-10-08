#define maxn 1000

struct huffnode
{
    char ch; //字符
    int weight; //权值
    int parent; //父节点下标
    int lchild;
    int rchild;
}HTree[maxn*2];
char *HCode[maxn*2];

/* 创建最优二叉树 */
/* 数组c[0..n-1]和w[0..n-1]存放了n个字符及其概率，构造Huffman树HT */


void select(int n, int &r1, int &r2)
{

    int minx1 = -1, ans1 = -1, ans2 = -1;
    for(int i = 1; i <= n; i++)
    {
        if(HT[i].parent == 0)
        {
            if(minx1 < 0 || HTree[i].weight < minx1)
            {
                minx1 = HTree[i].weight;
                ans1 = i;
            }
        }
    }
    minx1 = -1;
    for(int i = 1; i <= n; i++)
    {
        if(HTree[i].parent == 0 && i != ans1)
        {
            if(minx1 < 0 || HTree[i].weight < minx1)
            {
                minx1 = HTree[i].weight;
                ans2 = i;
            }
        }
    }

    r1 = ans1;
    r2 = ans2;
}

void createHTree(char c[], int w[], int n )
{
   int i, s1, s2;
   if (n <= 1)
       return;


   /* 根据n个权值构造n棵只有根结点的二叉树 */
   for (i=1; i<=n; i++)
   {
       HTree[i].ch = c[i-1];
       HTree[i].weight = w[i-1];
       HTree[i].parent = HTree[i].lchild = HTree[i].rchild = 0;
   }
   for (; i<2*n; ++i)
   {
       HTree[i].ch = '0';
       HTree[i].parent = 0;
       HTree[i].lchild = 0;
       HTree[i].rchild = 0;
   }
   /* 构造Huffman树 */
   for (i=n+1; i<2*n; i++)
   {
   /* 从HT[1..i-1]中选择parent为0且weight最小的两棵树，其序号为s1和s2 */
       select(i-1,s1,s2);
       HTree[s1].parent = i;
       HTree[s2].parent = i;
       HTree[i].lchild = s1;
       HTree[i].rchild = s2;
       HTree[i].weight = HTree[s1].weight + HTree[s2].weight;
   }
}

/* n个叶子结点在Huffman树HT中的下标为1~n  */
/* 第i（1<= i <= n）个叶子的编码存放HC[i]中 */
void HuffmanCoding(int n)
{
   char *cd;
   int i, start, c, f;
   if (n<=1)
       return;

   /* 分配n个字节的内存，用来存放当前得到的编码 */
   /* n个叶子结点最大的编码长度为n所以分配n个字节 */
   cd = (char*)malloc(n);
   cd[n-1] = '\0';
   for (i=1; i <= n; i++)
   {
       start = n-1;
       for (c = i,f = HTree[c].parent; f != 0; c = f, f = HTree[f].parent)
       {
           /**
           c获取结点的下标，f获取其父母，如果其父母的左孩子下标与c相等，说明处于左子树，填0

，否则在右子树，填1，然后c跳到父母
           */
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
       }
       /* 从叶子结点开始查找编码
          叶子结点的父结点的左子树为叶子结点，则编码为0
          否则就为父结点的右子树，则编码为1 */

       /* 分配内存，分配内存的字节数为当前得到的字符编码数 */
       HCode[i] = (char*)malloc(n-start);
       strcpy(HCode[i], &cd[start]);
   }
   free(cd);
}