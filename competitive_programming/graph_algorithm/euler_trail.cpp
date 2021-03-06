//無向グラフ：全ての頂点の次数が偶数
//有向グラフ：全ての頂点の相対次数が0
//Hierholzer's Algorithm

class EulerPath
{
public:
    vector<map<int,int> > G;
    vector<int> degree,path;
    int V; bool directed;
    EulerPath(int node_size, bool isdirected=false){
        V = node_size;
        directed = isdirected;
        G.resize(V);
        degree.resize(V,0);
    }
    void add_edge(int u,int v){
        if(directed){
            G[u][v]++;
            degree[u]++,degree[v]--;
        }else{
            G[u][v]++,G[v][u]++;
            degree[u]++,degree[v]++;
        }
    }
    void dfs(int u){
        while(!G[u].empty()){
			auto it = G[u].begin();
            int p = (*it).first,q = (*it).second;
            if(q > 0){
                if(directed){
                    G[u][p]--;
                }else{
                    G[u][p]--,G[p][u]--;
                }
                dfs(p);
            }else{
				it = G[u].erase(it);
			}
        }
        path.push_back(u);
    }
    bool solve(){
        int s=-1,t=-1;
        if(directed){
            rep(i,V){
                if(degree[i] != 0){
                    if(degree[i] == 1){
                        if(s >= 0) return false;
                        s = i;
                    }else if(degree[i] == -1){
                        if(t >= 0) return false;
                        t = i;
                    }else return false;
                }
            }
        }else{
            rep(i,V){
                if(degree[i] % 2){
                    if(s < 0) s = i;
                    else if(t < 0) t = i;
                    else return false;
                }
            }
        }
        if(s < 0) s = 0;
        dfs(s);
        reverse(path.begin(),path.end());
        return true;
    }
};
