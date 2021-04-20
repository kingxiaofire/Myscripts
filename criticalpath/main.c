#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int vex;
    int dut; //持续时间
    struct Node *next;
}Node;

typedef struct Hnode{
    int index; //入度 
    int data;
    Node *out;
}Hnode;

int ve[100]; //最晚发生时间 
int vl[100]; //最早发生时间
int stackS[100]; //入度为0的顶点序列栈
int stackT[100]; //逆拓扑序列栈
int topS = -1, topT = -1;

int TopoSort(Hnode A[], int m){
    int i, j, k, count = 0;
    Node *p;

    for(i=1; i<=m; i++){
        ve[i] = 0;//初始化最早发生时间 
        if( A[i].index==0 ){
            topS++;
            stackS[topS] = i;
        }
    }

    while ( topS!=-1 ){
        j = stackS[topS];
        topS--;
        topT++;
        stackT[topT] = j;
        count++;
        
        p = A[j].out;
        while (p!=NULL)
        {
            k = p->vex;
            A[k].index--;
            if( A[k].index==0 ){
                topS++;
                stackS[topS] = k;
            }
            if (ve[j] + p->dut > ve[k])
                ve[k] = ve[j] + p->dut;
            p = p->next;
        }
    }
    if( count<m ) return 0;
    else return 1;
}

void CriticalPath(Hnode A[], int m){
    int i, j, k, dut, ei, li;
    Node *p;
    if( !TopoSort(A, m) ){
        printf("* 工程图中存在环，无关键路径。\n");
        //return 0;
    }
    for(i=1;i<=m;i++)
        vl[i] = ve[m]; //始化为最早发生时间
    while( topT!=-1 ){
        j = stackT[topT];
        topT--; //按逆拓扑顺序求各顶点的vl
        p = A[j].out;
        while( p!=NULL){
            k = p->vex;
            if( vl[k] - p->dut < vl[j] )
                vl[j] = vl[k] - p->dut;
            p = p->next; 
        }
    }
    
    printf("* 关键路径(标记为'*')如下：\n\n");
    for(j=1;j<=m;j++){
        p = A[j].out;
        while( p!=NULL ){
            k = p->vex;
            dut = p->dut;
            ei = ve[j];
            li = vl[k] - dut;
            if( ei==li )
                printf("* <%d, %d>: dut=%d, e(i)=%d, l(i)=%d\n", A[j].data, A[k].data, dut, ei, li);
            else printf("  <%d, %d>: dut=%d, e(i)=%d, l(i)=%d\n", A[j].data, A[k].data, dut, ei, li);
            p = p->next;
        }
    }
}

int main(){
    int m, n, i;
    printf("* 请输入顶点个数：");
    scanf("%d",&m);
    printf("* 请输入边的条数：");
    scanf("%d",&n);
    Hnode A[m+1];

    for(i=1;i<=m;i++){
        A[i].index = 0;
        A[i].data = i;
        A[i].out = NULL;
    }
    
    int u, v, w;
    Node *p;
    printf("* 请输入%d条边以及该边的权：\n", n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);//读入各边以及边的权值
        p = (Node*)malloc( sizeof(Node) );
        A[v].index++;
        p->vex = v;
        p->dut = w;
        p->next = A[u].out;
        A[u].out = p;
    }
    CriticalPath(A, m);
    return 0;
}
