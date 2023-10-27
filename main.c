#include <stdio.h>
#define N 7
void programm11();
void programm12();
void programm13();
void programm14();
//Please uncomment to call one function at a time!
// To use same input for testing type: DisjointSets.exe < input.txt > output.txt
int main()
{
    printf( "To use same input for testing type: DisjointSets.exe < input.txt > output.txt\n");
    printf( "Type any number of couples of integers each time. Finally q and enter to finish your input\n");
   //programm11(); //Results  id[0] = 4	 id[1] = 1	 id[2] = 4	 id[3] = 4	 id[4] = 4	 id[5] = 6	 id[6] = 6 or {1} {0, 2, 3, 4} {5,6}
   //programm12();// Results id[0] = 2	 id[1] = 1	 id[2] = 4	 id[3] = 4	 id[4] = 4	 id[5] = 6	 id[6] = 6 or {0}{1}{2, 3, 4}{5,6}
    programm13();//Results  id[0] = 0	 id[1] = 1	 id[2] = 0	 id[3] = 0	 id[4] = 3	 id[5] = 5	 id[6] = 5 or {1}{0, 2, 3}{4}{5,6}
   //  programm14();//Results   id[0] = 0	 id[1] = 1	 id[2] = 0	 id[3] = 0	 id[4] = 3	 id[5] = 5	 id[6] = 5 or {1}{0, 2, 3}{4}{5,6}
     // programm14               id[0] = 0	 id[1] = 1	 id[2] = 0	 id[3] = 0	 id[4] = 3	 id[5] = 5	 id[6] = 5 //  Results using original book statements
    return 0;
}
void programm11(){

    int i, p, q, t, id[N];
    for (i = 0; i < N; i++)
    {
        id[i] = i;
    }
    // printf( "Type any number of couples of integers each time. Finally q and enter to finish your input\n");
    while (scanf("%d %d\n", &p, &q) == 2)
    {
        if (id[p] == id[q]) continue;
        for (t = id[p], i = 0; i < N; i++)
            if (id[i] == t) id[i] = id[q];
        printf("\t %d %d\n", p, q);
    }

    for (i = 0; i < N; i++)
        printf( "\t id[%i] = %i",i,id[i]);
    printf("\n");
}
void programm12()
{
    int i, p, q, j, id[N];
    for (i = 0; i < N; i++)
    {
        id[i] = i;
    }
    // printf( "Type any number of couples of integers each time. Finally q and enter to finish your input\n");
    while (scanf("%d %d\n", &p, &q)== 2)   {

        for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; j != id[j]; j = id[j]) ;
        if (i == j) continue;
        id[i] = j;
        printf("\t %d %d\n", p, q);
    }
    for (i = 0; i < N; i++)
        printf( "\t id[%i] = %i",i,id[i]);
    printf("\n");
}
//Weighted version of quick union probably wrong!
void programm13()
{
    int i, p, q,j, id[N], size[N];// extra array element size[i]  counts number of objects in the tree rooted at i
    for (i = 0; i < N; i++)
    {
        id[i] = i;
        size[ i ]=1;
    }
    //printf( "Type any number of couples of integers each time. Finally q and enter to finish your input\n");
    while (scanf("%d %d\n", &p, &q)== 2)
    {
        for (i = p; i != id [i];  i = id[ i ] )
            ;
        for (j = q; j != id [ j ];  j = id[ j ])
            ;
        if (i == j) continue;// check whether p and q are in the same component,whether   already connected?

        if (size[i] < size[j]) // Link root of smaller tree to root of larger tree
        {
            id[i] = j;
            size[j] += size [i] ;// Update the size[] array
        } else {
            id [j] = i;
            size[i] += size [j] ;
        }
        printf("\t %d %d\n", p, q);
    }
    for (i = 0; i < N; i++)
        printf( "\t id[%i] = %i",i,id[i]);
    printf("\n");
}
//Program 1.4 Path compression by halving
void programm14()
{
    int i, p, q, j, id[N], size[N];// extra array element size[i]  counts number of objects in the tree rooted at i
    for (i = 0; i < N; i++)
    {
        id[i] = i;
        size[ i ]=1;
    }
    // printf( "Type any number of couples of integers each time. Finally q and enter to finish your input\n");
    /*・Repeat:
    – read in pair of integers from standard input
    – if they are not yet connected, connect them and print out pair  p and q are connected iff they have the same id.*/
    while (scanf("%d %d\n", &p, &q)== 2)   {

        for (i = p; i != id [i];  i = id[ i ] )//id[i] is parent of i. Root of i is id[id[id[...id[i]...]]]
            id[i] = id[id[i]]; // Original statement from book
          // { int t = i; i = id[id[t]]; id[t] = i; }//Alternate from source code
        for (j = q; j != id [ j ];  j = id[ j ])//Make every other node in path point to its grandparent (thereby halving path length).
            id[j] = id[id[j]]; // Original from book
          // {int t = j; j = id[id[t]]; id[t] = j;} //Alternate from source code
        if (i == j) continue;// check whether p and q are in the same component,  already connected

        if (size[i] < size[j]) // Link root of smaller tree to root of larger tree
        {
            id[i] = j;
            size[j] += size [i] ;// Update the size[] array
        }  else {
            id [j] = i;
            size[i] += size [j] ;
        }
        printf("\t %d %d\n", p, q);
    }
    for (i = 0; i < N; i++)
        printf( "\t id[%i] = %i",i,id[i]);
    printf("\n");
}
