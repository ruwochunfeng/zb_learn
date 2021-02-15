package com.Diji.Suanfa;

import java.util.Scanner;
/*
 * author:�ܱ�
 * date:2017-05-10
 */

public class Tests {
	 //����������ݼ���
    static int [][] zuhe =new int[720][6];
    //���еݹ鼼��
    static int jishu = 0 ;
    //��Ǳ�����ȡ�ڵ�
	static int t=0,d=0,k=0,l=0,m=0,n=0;
    //����������Ԫ�ص�ֵ
	static int[] Distance;
	static int[] Queue ;
	static int len=0;
	 
	 public static String print(int []preIndex,int start,int end,int len)  
	    {  
	        int []path=new int[len];//������·��������  
	        int i=end;  
	        path[0]=i;  
	        int k=1;  
	        while (preIndex[i]!=start) {  
	            i=preIndex[i];  
	            path[k]=i;//�������  
	            k++;  
	        }  
	        path[k]=start;  
	        for (int j = k; j >0; j--) {  
//	        	if(path[j]>=4  && path[j]<=13){
//	        		path[j]=path[j]+1;
//	        	}else if(path[j]>13){
//	        		path[j]=path[j]+2;
//	        	}
	        	//���ս�������S����������N0
	        	if(path[j]!=0)
	            System.out.print("N"+path[j]+"->");  
	        }  
	        //���ս����E����������N17
	        if(path[0]!=17)
	        System.out.print("N"+path[0]+"->");  
	        return "";
	    }  

	//����ȨֵΪL1������ʼ�㵽�յ�����·������̾���    panduan��1�Ļ�������·�������������ֵĻ������
	    public static int DijistraSuanfa(int[][] shuju,int start,int end,int panduan){
	    	
	    	len =shuju[0].length;
	    	boolean[] isLabel = new boolean[len];
	    	Queue = new int[len]; //���ڼ�¼���·�����еĽڵ��ǰһ���ڵ����  
	    	int[] S =new int[len]; //���м���
	    	Distance = shuju[start].clone();// v0���������̾���ĳ�ʼֵ 
	    
	    	int index =start;
	        int count =0 ;//����Ŷ����˳�����Ŀ 
	        S[count]=index;// ���Ѿ���ŵ��±�����±꼯��  
	        isLabel[index]=true;//��ǵ�һ����
	      //���е��ʼ��Ϊ��һ����
	        for(int i = 0;i<len;i++){
	        	Queue[i]=start;
	        }
	        while(count<len){
	        	// ���v_start,��w[start][0]�����ҵ�����v_start����ĵ�    
	        	int min=Integer.MAX_VALUE;
	            // �ҳ���v_start������̵�Distance���±�  
	        	for(int i=0;i<Distance.length;i++){
	        		if(!isLabel[i]&&Distance[i]!=0&&i!=index){ // �����������б�,����û�б����    
		        		if(Distance[i]<=min){
		        			min = Distance[i];
		        			index = i;// ��¼������±�  
		        		}
	        		}
	        	}
	        	if(index == end ){//�Ѿ��ҵ���ǰ���ˣ��ͽ�������  
	        		break;
	        	}
	        	isLabel[index] =true;
	        	count++;
	        	S[count] = index;
	        	
	        	for(int i=0;i<Distance.length;i++){
	        		//�����ǰ���� ����û�б�� ���������ڵ�
	        		if(Distance[i] == 0 && !isLabel[i]&&shuju[index][i]!=0){//�����ǰ���ɴ�����ڿɴ���  
	        			Distance[i]=shuju[index][i]+Distance[index];
	        			Queue[i] = index;
	        		}else if(shuju[index][i]!=0&&Distance[i]+shuju[index][i]<Distance[i]){ // �����ǰ�ɴ�����ڵ�·������ǰ���̣�������ɸ��̵�·��  
	        			Distance[i] = Distance[i]+shuju[index][i];
	        			Queue[i] = index;//�������·���е�ǰ�ӵ��ǰһ���ӵ�  
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
	    //�ݹ�����
	    public static String pailie(int[] pai ,int index ,int length){
	    	
	    	if(index == length)//����ݹ鵽���ʱ������󽻻���Ԫ�ؼ�ʱ���һ��Ԫ��ʱ�ʹ�ӡ����
	        { 
	    		int []shuju =new int[6];
	            for(int i = 0; i <length; i++)
	               shuju[i]=pai[i];
	             zuhe[jishu++]=shuju;
	        }
	        else
	        {
	            for(int i = index; i <length; i++)
	            {//ѭ������ʹ�õ�ǰλ�ú�ߵ�ÿһ��Ԫ�ض��͵�ǰ��ȵĵ�һ��Ԫ�ؽ���һ��
	                swap(pai,index,i);//ʹ�����һ��Ԫ�ؽ���
	                pailie(pai,index+1,length);//����ݹ飬��ʱ��ȷ��ǰ�ߵ�Ԫ�أ������������е�ȫ������ʽ��
	                swap(pai,index,i);//�ָ�����֮ǰ��״̬
	            }
	        }
	    	return "";
	    }
	public static void main(String[] args) {
		   //�����κ�Լ�������µ�ԭ����
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
			
					//�䴦���������е���������
//	        System.out.println(dijkstra(shuju,0,17)); 
					System.out.println("���ݴ��������ڶ����жϣ���ϵͳ�޽⣬ֻ��������Ž�");
					System.out.println("���������Ϊ��");
					for(int i=0;i<shuju[0].length;i++){
						for(int j=0;j<shuju[0].length;j++){
							System.out.print(shuju[i][j]+" ");
						}
						System.out.println("");
					}
					System.out.println(pailie(paile,0,paile.length));
					//���������� �������еļ���ע�͵��� ������̫�࣬���Կ��ĵ��Ľ�ͼ
//					System.out.println("�������Ϊ��");
//					for(int j=0;j<zuhe.length;j++){
//						for(int i =0;i<zuhe[j].length;i++){
//							System.out.print(zuhe[j][i]+" ");
//						}
//						System.out.println("");
//					}
					//�����������
					int min = Integer.MAX_VALUE;
					System.out.println("������ݴ��Ž�");
                  
					for(int i=0;i<zuhe.length;i++){
						//ѭ��������Сֵ���������·������Ϊ����̫��
						 int sum = DijistraSuanfa(shuju,0,zuhe[i][0],0)+
								 DijistraSuanfa(shuju,zuhe[i][0],zuhe[i][1],1)+
						   DijistraSuanfa(shuju,zuhe[i][1],zuhe[i][2],1)+
						   DijistraSuanfa(shuju,zuhe[i][2],zuhe[i][3],1)+
						   DijistraSuanfa(shuju,zuhe[i][3],zuhe[i][4],1)+
						 DijistraSuanfa(shuju,zuhe[i][4],zuhe[i][5],1)+
						 DijistraSuanfa(shuju,zuhe[i][5],17,1);
						 System.out.println("");
                         //����ȥ��Сֵ,�����ڵ��ǣ�ȡ����Сֵ��������·��
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
					//��������������ݣ���ʵ���������ηֶ�������·�ڵ㲢�ϲ�Ϊ���·
					 int ss =DijistraSuanfa(shuju,0,t,1)+
					 DijistraSuanfa(shuju,t,d,1)+
			   DijistraSuanfa(shuju,d,k,1)+
			   DijistraSuanfa(shuju,k,l,1)+
			   DijistraSuanfa(shuju,l,m,1)+
			   DijistraSuanfa(shuju,m,n,1)+
			   DijistraSuanfa(shuju,n,17,1);
				    System.out.println("E"); 
					System.out.println("�����Ϊ��"+(min)); 
					//��ֹ����exe�ļ�����
					Scanner scanner =new Scanner(System.in);
					while(scanner.nextLine()!="bye"){
						break;
					}
	}

		
	
}
