/*
 

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X


*/
public class Solution {
    int m;
    int n;
	public void solve(ArrayList<ArrayList<Character>> a) {
	    m = a.size();
	    n = a.get(0).size();
	    
	    for(int i = 0; i < m; i++){
	        for(int j = 0; j < n; j++){
	            if(a.get(i).get(j) == 'O'){
	                a.get(i).set(j,'*');
	            }
	        }
	    }
	    
	    for(int i = 0; i < m; i++){
	        if(a.get(i).get(0) == '*'){
	            solve(a,i,0,'*','O');
	        }
	    }
	    
	    for(int i = 0; i < m; i++){
	        if(a.get(i).get(n-1) == '*'){
	            solve(a,i,n-1,'*','O');
	        }
	    }
	    
	    for(int i = 1; i < n-1; i++){
	        if(a.get(0).get(i) == '*'){
	            solve(a,0,i,'*','O');
	        }
	    }
	    
	    for(int i = 1; i < n-1; i++){
	        if(a.get(m-1).get(i) == '*'){
	            solve(a,m-1,i,'*','O');
	        }
	    }
	    
	    for(int i = 0; i < m; i++){
	        for(int j = 0; j < n; j++){
	            if(a.get(i).get(j) == '*'){
	                a.get(i).set(j,'X');
	            }
	        }
	    }
	}
	
	public void solve(ArrayList<ArrayList<Character>> a,int i,int j,char oldx,char newx){
	    if(i<0 || i>=m || j<0 || j>=n){
	        return;
	    }
	    if(a.get(i).get(j) != oldx){
	        return;
	    }
	    
	    a.get(i).set(j,newx);
	    
	    solve(a,i+1,j,oldx,newx);
	    solve(a,i-1,j,oldx,newx);
	    solve(a,i,j+1,oldx,newx);
	    solve(a,i,j-1,oldx,newx);
	}
}
