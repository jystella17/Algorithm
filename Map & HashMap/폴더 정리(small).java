// BOJ 22860 폴더 정리 (small) (G3)
// HashMap + HashSet + 재귀

import java.io.*;
import java.util.*;

class Child {
    String name;
    int isFolder;
    
    public Child(String name, int isFolder) {
        this.name = name;
        this.isFolder = isFolder;
    }
}

public class Main {
    
  public static HashMap<String, List<Child>> fileSystem = new HashMap<>();
    
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st = new StringTokenizer(br.readLine());
	    
	    int n = Integer.parseInt(st.nextToken());
	    int m = Integer.parseInt(st.nextToken());

	    for(int i=0; i<n+m; i++) {
	        st = new StringTokenizer(br.readLine());
	        String parent = st.nextToken();
	        String child = st.nextToken();
	        int isFolder = Integer.parseInt(st.nextToken());
	        
	        Child c = new Child(child, isFolder);
	        List<Child> children;
	  
	        if(fileSystem.containsKey(parent)) {
	            children = fileSystem.get(parent);
	        } else {
	            children = new ArrayList<>();
	        }
	        
	        if(!fileSystem.containsKey(child)) {
	            fileSystem.put(child, new ArrayList<>());
	        }
	        
	        children.add(c);
	        fileSystem.put(parent, children);
	    }
	    
	    st = new StringTokenizer(br.readLine());
	    int q = Integer.parseInt(st.nextToken());

	    for(int i=0; i<q; i++) {
	        String query = new StringTokenizer(br.readLine()).nextToken();
	        String[] routes = query.split("/");
	        query = routes[routes.length - 1];
	        
	        List<String> fileList = findParent(query, new ArrayList<>());
	        Set<String> fileTypes = new HashSet<>(fileList);
	        System.out.println(fileTypes.size() + " " + fileList.size());
	    }
	}
	
	public static List<String> findParent(String current, List<String> fileList) {
	    List<Child> children = fileSystem.get(current);
	    
	    for(Child c: children) {
	        if(c.isFolder == 0) {
	            fileList.add(c.name);
	        } else {
	            fileList = findParent(c.name, fileList);
	        }
	    }
	    return fileList;
	}
}
