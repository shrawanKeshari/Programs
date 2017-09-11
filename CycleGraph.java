import java.util.ArrayList;
import java.util.Scanner;

public class CycleGraph{

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int vertex = sc.nextInt();
		int edge = sc.nextInt();
		int[][] a = new int[vertex+1][vertex+1];
		for(int i = 0; i < edge; i++){
		    int u = sc.nextInt();
		    int v = sc.nextInt();
		    a[u][v] = 1;
		    a[v][u] = 1;
		}
		boolean[] visited = new boolean[vertex+1];
		int[] parent = new int[vertex+1];
		for(int i = 1; i <= vertex; i++){
		    visited[i] = false;
		    parent[i] = -1;
		}
	    System.out.println(cycle(a, visited, parent, vertex));
	}
		
	public static boolean cycle(int[][] a,boolean[] visited,int[] parent,int n) {
		for(int i=1;i<=n;i++) {
			visited[i]=false;
			parent[i]=-1;
		}
		for(int i=1;i<=n;i++) {
			if(visited[i]==false) {
				if(isCycle(i,visited,parent,a,n)) {
					return true;
				}
			}
		}
		return false;
	}
	
	public static boolean isCycle(int u,boolean[] visited,int[] parent,int[][] a,int n) {
		visited[u]=true;
		for(int i=1;i<=n;i++) {
		    if(i!=u && a[u][i]!=0){
		        if((visited[i]==false)) {
				    parent[i]=u;
				    if(isCycle(i, visited, parent, a, n)) {
				    	return true;
				    }
		    	}else if(i!=parent[u]) {
				    return true;
			    }
		    }
		}
		return false;
	}
}
