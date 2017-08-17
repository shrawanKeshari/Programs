/*
  The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0’s) or contain magic orbs that increase the knight’s health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight’s minimum initial health so that he is able to rescue the princess.
Ex: -2(K),-3 ,3
    -5   ,-10,1
    10   ,30 ,-5(P)

Solution: 7
*/

public class Solution {
	public int calculateMinimumHP(ArrayList<ArrayList<Integer>> a) {
	    int m = a.size();
	    int n = a.get(0).size();
	    int[][] table = new int[m][n];
	    
	    if(a.get(m-1).get(n-1) >= 0){
	        table[m-1][n-1] = 1;
	    }else{
	        table[m-1][n-1] = 1-a.get(m-1).get(n-1);
	    }
	    
	    for(int i = m-2; i >= 0; i--){
	        table[i][n-1] = value(a.get(i).get(n-1),table[i+1][n-1]);
	    }
	    
	    for(int j = n-2; j >= 0; j--){
	        table[m-1][j] = value(a.get(m-1).get(j),table[m-1][j+1]);
	    }
	    
	    for(int i = m-2; i >= 0; i--){
	        for(int j = n-2; j >= 0; j--){
	            table[i][j] = Math.min(value(a.get(i).get(j),table[i+1][j]),value(a.get(i).get(j),table[i][j+1]));
	        }
	    }
	    
	    return table[0][0];
	}
	
	public int value(int a,int b){
	    if(a == 0){
	        return b;
	    }
	    if(a > 0){
	        if(a >= b){
	            return 1;
	        }
	        
	        return b-a;
	    }
	    
	    return b-a;
	}
}
