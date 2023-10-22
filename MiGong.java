
public class MiGong{
	public static void main(String[] args) {
		int map[][] = new int[8][7];
		for(int i=0 ;i<map.length; i++){
			for(int j=0 ;j<map[i].length ; j++){
				map[0][j]=1;
				map[7][j]=1;
			}
			System.out.println();
		}
		for(int i=0;i<map.length;i++){
			for(int j=0;j<map[i].length;j++){
				map[i][0]=1;
				map[i][6]=1;
			}
		}
		map[3][1]=1;
		map[3][2]=1;
		T t1 = new T();
		t1.findway(map,1,1);
		for(int i=0;i<map.length;i++){
			System.out.println();
			for(int j=0;j<map[i].length;j++){
				System.out.print(map[i][j]+"\t");
			}
			System.out.println("");
		}

	}
}

class T{
	public boolean findway(int map[][],int i,int j){
		if(map[6][5]==2){
			return true;
		}
		else{
			if(map[i][j]==0){
				map[i][j]=2;
				if(findway(map,i,j+1)){   //右移动
					return true;
				}else if(findway(map,i+1,j)){  //下移动
					return true;
				}else if(findway(map,i,j-1)){   //左移动
					return true;
				}else if(findway(map,i-1,j)){   //上移动
					return true;
				}else{
					map[i][j]=3;
					return false;
				}
			}else{
				return false;
			}
		}
	}
}