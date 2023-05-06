#include &lt;cstdlib&gt;
#include &lt;fstream&gt;
#include &lt;iomanip&gt;
#include &lt;iostream&gt;

#define MIN_SIZE 30
#define MAX_SIZE 1000

using namespace std;
int merge(int a[],int p,int q,int r)
{
int c=0;
int n1=q-p+1;
int n2=r-q;
int la[n1+1];
int ra[n2+1];
for(int i=0;i&lt;n1;i++)
{
la[i]=a[p+i];
}
for(int j=0;j&lt;n2;j++)
{
ra[j]=a[q+j+1];
}
la[n1]=INT_MAX;
ra[n2]=INT_MAX;

int i=0,j=0;
for(int k=p;k&lt;=r;k++)
{
if(la[i]!= INT_MAX &amp;&amp; ra[i]!=INT_MAX)
{
c++;
}
if(la[i]&lt;ra[j])
{
a[k]=la[i];
i++;
}
else
{
a[k]=ra[j];
j++;
}
}
return c;
}

int mergesort(int a[],int p,int r)
{
int c=0;
if(p&lt;r)
{
int q=(p+r)/2;
c+=mergesort(a,p,q);

c+=mergesort(a,q+1,r);
c+=merge(a,p,q,r);
}
return c;
}

int main()
{

cout&lt;&lt;&quot;input size | best case | average case | worst case\n&quot;;

try
{
ofstream fout(&quot;./results.csv&quot;);
fout &lt;&lt; &quot;size,best,avg,worst\n&quot;;
for(int i=0;i&lt;100;i++)
{
int size=rand()% (MAX_SIZE +1-MIN_SIZE) + MIN_SIZE;
int *a=new int[size];
int compare=0;

cout&lt;&lt;size&lt;&lt;&quot; &quot;;
fout&lt;&lt; size &lt;&lt; &quot;,&quot;;

//best case
for(int i=0;i&lt;size;i++)
{
a[i]=i+1;
}

compare=mergesort(a,0,size-1);
cout&lt;&lt;&quot; &quot;&lt;&lt;compare&lt;&lt;&quot; &quot;;
fout&lt;&lt;compare&lt;&lt;&quot;,&quot;;

//average case
try
{
ifstream fin(&quot;./random.txt&quot;);
for(int i=0;i&lt;size;i++)
{
fin&gt;&gt;a[i];
}
fin.close();
compare=mergesort(a,0,size-1);
fout&lt;&lt;compare&lt;&lt;&quot;,&quot;;
cout&lt;&lt;&quot; &quot;&lt;&lt;compare&lt;&lt;&quot; &quot;;
}
catch(exception e)
{
cerr &lt;&lt; e.what();

return -1;
}

//worst case
for(int i=0;i&lt;size;i++)
{
a[i]=size-i;
}
compare=mergesort(a,0,size-1);

fout&lt;&lt;compare&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot; &quot;&lt;&lt;compare&lt;&lt;&quot;\n&quot;;
}
fout.close();
return 0;

}
catch(exception e)
{
cerr &lt;&lt; e.what();
return -1;
}

}
