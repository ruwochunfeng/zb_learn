package com.Diji.Suanfa;

import java.util.Scanner;
/*
 * author:周兵
 * date:2017-05-10
 */

public class Tests {
	 //排列组合数据集合
    static int [][] zuhe =new int[720][6];
    //排列递归技术
    static int jishu = 0 ;
    //标记变量，取节点
	static int t=0,d=0,k=0,l=0,m=0,n=0;
    //交换数组中元素的值
	static int[] Distance;
	static int[] Queue ;
	static int len=0;
	 
	 public static String print(int []preIndex,int start,int end,int len)  
	    {  
	        int []path=new int[len];//定义存放路径的数组  
	        int i=end;  
	        path[0]=i;  
	        int k=1;  
	        while (preIndex[i]!=start) {  
	            i=preIndex[i];  
	            path[k]=i;//反向遍历  
	            k++;  
	        }  
	        path[k]=start;  
	        for (int j = k; j >0; j--) {  
//	        	if(path[j]>=4  && path[j]<=13){
//	        		path[j]=path[j]+1;
//	        	}else if(path[j]>13){
//	        		path[j]=path[j]+2;
//	        	}
	        	//最终结果有输出S，所以抛弃N0
	        	if(path[j]!=0)
	            System.out.print("N"+path[j]+"->");  
	        }  
	        //最终结果有E，所有抛弃N17
	        if(path[0]!=17)
	        System.out.print("N"+path[0]+"->");  
	        return "";
	    }  

	//查找权值为L1矩阵，起始点到终点的最短路径和最短距离    panduan是1的话输出最短路径，是其他数字的话不输出
	    public static int DijistraSuanfa(int[][] shuju,int start,int end,int panduan){
	    	
	    	len =shuju[0].length;
	    	boolean[] isLabel = new boolean[len];
	    	Queue = new int[len]; //用于记录最短路径树中的节点的前一个节点序号  
	    	int[] S =new int[len]; //所有集合
	    	Distance = shuju[start].clone();// v0到各点的最短距离的初始值 
	    
	    	int index =start;
	        int count =0 ;//被标号顶点的顺序或数目 
	        S[count]=index;// 把已经标号的下标存入下标集中  
	        isLabel[index]=true;//标记第一个点
	      //所有点初始化为第一个点
	        for(int i = 0;i<len;i++){
	        	Queue[i]=start;
	        }
	        while(count<len){
	        	// 标号v_start,即w[start][0]行中找到距离v_start最近的点    
	        	int min=Integer.MAX_VALUE;
	            // 找出与v_start距离最短的Distance的下标  
	        	for(int i=0;i<Distance.length;i++){
	        		if(!isLabel[i]&&Distance[i]!=0&&i!=index){ // 如果到这个点有边,并且没有被标号    
		        		if(Distance[i]<=min){
		        			min = Distance[i];
		        			index = i;// 记录下这个下标  
		        		}
	        		}
	        	}
	        	if(index == end ){//已经找到当前点了，就结束查找  
	        		break;
	        	}
	        	isLabel[index] =true;
	        	count++;
	        	S[count] = index;
	        	
	        	for(int i=0;i<Distance.length;i++){
	        		//如果以前相连 ，且没有标记 跟新相连节点
	        		if(Distance[i] == 0 && !isLabel[i]&&shuju[index][i]!=0){//如果以前不可达，则现在可达了  
	        			Distance[i]=shuju[index][i]+Distance[index];
	        			Queue[i] = index;
	        		}else if(shuju[index][i]!=0&&Distance[i]+shuju[index][i]<Distance[i]){ // 如果以前可达，但现在的路径比以前更短，则更换成更短的路径  
	        			Distance[i] = Distance[i]+shuju[index][i];
	        			Queue[i] = index;//更新最短路径中当前接点的前一个接点  
//		                }  
	        		}
	        	}
	        	
	        }
//	        for(int i=0;i<len;i++){
//        	    
//        		System.out.print("N"+S[i]+"->");
//        		
//        	
//           }
//	        System.out.println("");
//	        for(int i=0;i<len;i++){
//	        	    
//	        		System.out.print("N"+Queue[i]+"->");
//	        	
//	        }
//	        System.out.println("");
	        if(panduan==1){
	        print(Queue,start,end,Distance.length); 
	        }
	    	
	        return Distance[end]-Distance[start];
	    }
	  
	
	    public static void swap(int[] data,int a,int b){
	    	
	    	int temp =data[a] ;
	    	data[a]  =data[b];
	    	data[b]= temp;
	 
	    }
	    //递归排列
	    public static String pailie(int[] pai ,int index ,int length){
	    	
	    	if(index == length)//如果递归到深层时，到最后交换的元素即时最后一个元素时就打印出来
	        { 
	    		int []shuju =new int[6];
	            for(int i = 0; i <length; i++)
	               shuju[i]=pai[i];
	             zuhe[jishu++]=shuju;
	        }
	        else
	        {
	            for(int i = index; i <length; i++)
	            {//循环遍历使得当前位置后边的每一个元素都和当前深度的第一个元素交换一次
	                swap(pai,index,i);//使得与第一个元素交换
	                pailie(pai,index+1,length);//深入递归，此时已确定前边的元素，处理后边子序列的全排列形式。
	                swap(pai,index,i);//恢复交换之前的状态
	            }
	        }
	    	return "";
	    }
	public static void main(String[] args) {
		   //不加任何约束条件下的原数组
			int[][] shuju ={      {0,3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			                      {3,0,1,0,1,0,0,0,0,4,0,0,0,0,0,0,0,0},
			                      {1,1,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0},
			                      {1,0,1,0,0,2,2,1,0,0,0,0,0,0,0,0,0,0},
			                      {0,1,2,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
			                      {0,0,1,2,1,0,1,0,0,3,1,0,3,0,0,0,0,0},
			                      {0,0,0,2,0,1,0,1,2,0,0,0,2,4,3,0,0,0},
			                      {0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0},
			                      {0,0,0,0,0,0,2,1,0,0,0,0,0,0,1,3,0,0},
			                      {0,4,0,0,1,3,0,0,0,0,1,1,0,0,0,0,0,0},
			                      {0,0,0,0,0,1,0,0,0,1,0,1,2,0,0,0,0,0},
			                      {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0},
			                      {0,0,0,0,0,3,2,0,0,0,2,0,0,2,0,0,1,0},
			                      {0,0,0,0,0,0,4,0,0,0,0,0,2,0,1,2,2,1},
			                      {0,0,0,0,0,0,3,0,1,0,0,0,0,1,0,1,0,0},
			                      {0,0,0,0,0,0,0,0,3,0,0,0,0,2,1,0,0,4},
			                      {0,0,0,0,0,0,0,0,0,0,0,1,1,2,0,0,0,1},
			                      {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,4,1,0}
			 };			
			 
					Queue= new int[shuju[0].length];
				                    
					int[] paile ={2,4,7,12,13,14};
			
					//输处到窗口所有的输入数据
//	        System.out.println(dijkstra(shuju,0,17)); 
					System.out.println("根据大赛条件第二条判断，该系统无解，只能输出次优解");
					System.out.println("输入的数据为：");
					for(int i=0;i<shuju[0].length;i++){
						for(int j=0;j<shuju[0].length;j++){
							System.out.print(shuju[i][j]+" ");
						}
						System.out.println("");
					}
					System.out.println(pailie(paile,0,paile.length));
					//输出排列组合 ，该所有的集合注释掉了 ，数据太多，可以看文档的截图
//					System.out.println("排列组合为：");
//					for(int j=0;j<zuhe.length;j++){
//						for(int i =0;i<zuhe[j].length;i++){
//							System.out.print(zuhe[j][i]+" ");
//						}
//						System.out.println("");
//					}
					//计算排列组合
					int min = Integer.MAX_VALUE;
					System.out.println("输出数据次优解");
                  
					for(int i=0;i<zuhe.length;i++){
						//循环计算最小值，但不输出路径，因为数据太多
						 int sum = DijistraSuanfa(shuju,0,zuhe[i][0],0)+
								 DijistraSuanfa(shuju,zuhe[i][0],zuhe[i][1],1)+
						   DijistraSuanfa(shuju,zuhe[i][1],zuhe[i][2],1)+
						   DijistraSuanfa(shuju,zuhe[i][2],zuhe[i][3],1)+
						   DijistraSuanfa(shuju,zuhe[i][3],zuhe[i][4],1)+
						 DijistraSuanfa(shuju,zuhe[i][4],zuhe[i][5],1)+
						 DijistraSuanfa(shuju,zuhe[i][5],17,1);
						 System.out.println("");
                         //计算去最小值,并将节点标记，取得最小值后可以输出路径
						 if(sum<min){
							 min = sum;
							 t=zuhe[i][0];
							 d=zuhe[i][1];
							 k=zuhe[i][2];
							 l=zuhe[i][3];
                             m=zuhe[i][4];
		                     n=zuhe[i][5];
						 }
						 

						 
							
					}
					System.out.print("S"+"->"); 
					//看起来像计算数据，但实际上是依次分段输出最短路节点并合并为最短路
					 int ss =DijistraSuanfa(shuju,0,t,1)+
					 DijistraSuanfa(shuju,t,d,1)+
			   DijistraSuanfa(shuju,d,k,1)+
			   DijistraSuanfa(shuju,k,l,1)+
			   DijistraSuanfa(shuju,l,m,1)+
			   DijistraSuanfa(shuju,m,n,1)+
			   DijistraSuanfa(shuju,n,17,1);
				    System.out.println("E"); 
					System.out.println("最后结果为："+(min)); 
					//防止生成exe文件闪退
					Scanner scanner =new Scanner(System.in);
					while(scanner.nextLine()!="bye"){
						break;
					}
	}

		
	
}
