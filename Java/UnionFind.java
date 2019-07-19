public class UnionFind {

    private int[] id;
    private int[] sz;

    public UnionFind(int N){
        id = new int[N];
        sz = new int[N];

        for(int i = 0; i< N;i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }
    private int root(int i )
    {
        while(i != id[i])
        {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    public boolean connected(int p,int q)
    {
        return root(p) == root(q);
    }
    public void connect(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if (i == j) return;
        if (sz[i] > sz[j])
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        else
        {
            id[i] = j;
            sz[j] += sz[i];
        }
    }
    public static void main(String[] args)
    {
        UnionFind x = new UnionFind(10);
        x.connect(1,4);
        x.connect(4,5);
        x.connect(5,8);
        System.out.println(x.connected(1,8));
    }

}
