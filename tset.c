#include <stdio.h> 
 #include <malloc.h>
 
 #define AddrMAX 1000004
 
 typedef struct AnsNode
 {
     int addr, data;
 }anode, *panode;
 
 int main(void)
{
     int n, k, i, j, block, rest, top = 0;
     int start, temp;
     
     scanf("%d %d %d", &start, &n, &k);
     
     int* data = (int *)malloc(sizeof(int)*(AddrMAX));
     int* next = (int *)malloc(sizeof(int)*(AddrMAX));
     
     panode ans = (panode)malloc(sizeof(anode)*(n+1));
     
     for (i = 0; i < n; i++)
     {
         scanf("%d", &temp);
         scanf("%d %d", &data[temp], &next[temp]);
     }
     
     // 按地址将链构造好放入ans中 
     while (start != -1)
     {
         ans[top].data = data[start];
         ans[top].addr = start;
         start = next[start];
         top++;
     }
     n = top;
     
     // 每 K 段输出一次，并且处理最后一次不足k个的情况，关键点在于“段与段”之间“地址 ”的拼接 
     block = n / k; rest = n % k;
     for (j = 0; j < block; j++)
     {
         for (i = (j + 1)*k - 1; i > j*k; i--)
         {
             printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i-1].addr);
         }
         printf("%05d %d ", ans[i].addr, ans[i].data);
         if (rest == 0)
         {
             if (j == block - 1) printf("-1");
             else printf("%05d", ans[(j+2)*k-1].addr);
         } else
         {
             if (j == block - 1) printf("%05d", ans[(j+1)*k].addr);
             else printf("%05d", ans[(j+2)*k-1].addr);
         }
         printf("\n");
     }
     if (rest != 0)
     {
         for (i = block*k; i < n - 1; i++) printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i+1].addr);
         printf("%05d %d -1\n", ans[i].addr, ans[i].data);
     }
     
     return 0;
 }
