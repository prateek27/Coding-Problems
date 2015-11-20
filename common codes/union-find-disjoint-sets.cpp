vi pset;//pset means parent set
void iniset(int N)
{
	pset.assign(N,0);
	forr(int i=0;i<N;i++)
		pset[i]=i;
}
int findset(int i)
{
	return (pset[i]==i)?i:(pset[i]=findset(pset[i]));
}
bool issameset(int i,int j)
{
	return findset(i)==findset(j);
}
void unionset(int i,int j)
{
	pset[findset(i)]=findset(j);
}
