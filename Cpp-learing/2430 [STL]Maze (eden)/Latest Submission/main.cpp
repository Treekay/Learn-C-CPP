#include <iostream>  
#include <queue>  
#define MAX 21  
using namespace std;    

char map[MAX][MAX];

class maze {
private:
	int row;
	int col;
	int leaststep;
public:
	struct point{  
	    int x, y, num;  
	    point(int row,int col,int poi){  
	        x = row;  
	        y = col;  
	        num = poi;  
	    }  
	}; 
	maze(int _row, int _col){
		row = _row;
		col = _col;
		leaststep = 0;
	}
	int bfs(int sx, int sy){  
		queue <point> q;
		int visit[MAX][MAX]={0}; 
		int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; 

	    q.push(point(sx, sy, 0)); 
	    visit[sx][sy] = 1;  
	    while(!q.empty())
	    {  
	        point p = q.front();  
	        q.pop();  
	        if (map[p.x][p.y] == 'E'){  
	            leaststep = p.num;  
	            break;  
	        }  
	        for(int i = 0; i < 4; i++){  
	            int a = p.x + dir[i][0];  
	            int b = p.y + dir[i][1];  
	            if(map[a][b] != '#' && map[a][b] != '!' && visit[a][b] == 0 
	            	&& a >= 0 && b >= 0 && a < row && b < col){  
	                q.push(point(a, b, p.num + 1));  
	                visit[a][b] = 1;
	            }  
	        }  
	    }
	    return leaststep;   
	}  
	int GetLeastStep(){
		return leaststep;
	}
}; 
 
void test(){
	int s1,s2;
    int n, m;
    cin >> n >> m;  
    for (int row = 0; row < n;row++){  
    	for (int col = 0; col < m; col++){
    		 cin >> map[row][col];  
    	}
    }
    maze game(n, m);
    for (int row = 0; row < n; row++){  
        for (int col = 0; col < m; col++){  
            if(map[row][col] == 'S'){  
                s1 = row;  
                s2 = col;  
            }  
        }  
    }
    if (game.bfs(s1, s2) != 0) cout << game.GetLeastStep() << endl;  
	else cout << "-1" << endl;  
}

int main()  
{  
   	test();
    return 0;  
}  