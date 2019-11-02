 #include<stdio.h>  
 #include<stdlib.h>  
 #include<math.h>  
   
 int graeff();  
 int main(){  
   char status[10]={0};  
   int power;  
   system("clear");  
   printf("**********************************************\n");  
   printf("\tGRAEFF'S ROOT SQUARING METHOD\n");  
   printf("**********************************************\n");  
   while(1){  
     graeff(atoi(status));  
   }      
 }  
   
 int graeff(){  
   int power,ctr,ctr1,ctr2,ctr3,i;  
     float temp=0,div=0.5,tolerance=0;  
   printf("\nEnter the Highest Power Of Polynomial (0 to exit) = ");  
     scanf("%d",&power);  
     if(power==0){  
       system("clear");  
       printf("\n\n\tTHANK YOU\n\n\n");  
       exit(0);  
     }  
     if(power<0){  
       printf("ERROR: Can not find root for minus power!!!\n");  
       return 0;  
     }  
     
   double coe[power+1],min_coe[power+1],new_coe[2*(power+1)-1],func[power+1],o_ans[power+1],n_ans[power+1];  
   for(i=0;i<=power;i++){  
     coe[i]=0;func[i]=0;min_coe[i]=0;o_ans[i]=0;n_ans[i]=0;  
   }  
   for(ctr=0;ctr<=2*power;ctr++){  
     new_coe[i]=0;  
   }  
   for(ctr=power;ctr>=0;ctr--){  
       printf("Enter the coefficient of power %d = ",ctr);  
       scanf("%lf",&coe[ctr]);  
   }  
   for(ctr=power;ctr>=0;ctr--){  
     func[ctr]=coe[ctr];  
   }  
   printf("\nEnter the Error Tolerance = ");  
     scanf("%f",&tolerance);  
   printf("\n");  
   i=1;  
   int j=1;  
     while(i){  
     //printf("Now coefficient values accoroding to the power\n");  
     //for(ctr=power;ctr>=0;ctr--){  
     //  printf("\t%dth power coefficient = %f\n",ctr,coe  
     //            [ctr]);  
     //}  
     printf("\niteration %d\n",j);  
     j++;  
     for(ctr=power;ctr>=0;ctr--){  
       min_coe[ctr]=coe[ctr];  
     }  
     for(ctr=power-1;ctr>=0;ctr=ctr-2){  
       min_coe[ctr]=(-1*min_coe[ctr]);  
     }  
     ctr2=2*power;  
     ctr3=2*power;  
     for(ctr=power;ctr>=0;ctr--){  
       for(ctr1=power;ctr1>=0;ctr1--,ctr2--){  
         new_coe[ctr2]=new_coe[ctr2]+  
             (coe[ctr]*min_coe[ctr1]);  
       }  
       ctr3--;  
       ctr2=ctr3;  
     }  
     for(ctr=power,ctr2=2*power;ctr>=0,ctr2>=0;ctr2=ctr2-2,ctr--){  
       coe[ctr]=new_coe[ctr2];  
     }  
     for(ctr=0;ctr<=2*power;ctr++){  
       new_coe[ctr]=0;  
     }  
     for(ctr=0;ctr<power;ctr++){  
         temp=fabs(coe[ctr])/fabs(coe[ctr+1]);  
         n_ans[ctr]=pow(temp,div);  
       }  
       printf("\tRoots: ");  
       for(ctr=0;ctr<power;ctr++){  
           printf("\t%f",n_ans[ctr]);  
       }  
       printf("\n\tError: ");  
       for(ctr=0;ctr<power;ctr++){  
           printf("\t%f",(n_ans[ctr]-o_ans[ctr])/o_ans[ctr]);  
       }  
       int count=0;  
       for(ctr=0;ctr<power;ctr++){  
         if((n_ans[ctr]-o_ans[ctr])/n_ans[ctr]<=tolerance){  
           count++;  
         }  
         if(j==51){  
           printf("\nRoots are not identified!!!\n");  
           return 0;  
         }  
         o_ans[ctr]=n_ans[ctr];  
         if(count==power){  
           i=0;  
         }  
       }      
     printf("\n");  
       div=div/2;  
     }  
     for(ctr=0;ctr<=power;ctr++){  
     coe[ctr]=0;  
   }  
     printf("\n");  
   for(ctr=0;ctr<power;ctr++){    
     float x1=o_ans[ctr];  
     float x2=-1*(o_ans[ctr]);      
     float y1=0;  
     float y2=0;  
     for(ctr1=0;ctr1<=power;ctr1++){      
       y1+=pow(x1,ctr1)*func[ctr1];  
     }  
     printf("When %f function = %f\t",x1,y1);  
     for(ctr1=0;ctr1<=power;ctr1++){      
       y2+=pow(x2,ctr1)*func[ctr1];  
     }  
     printf("When %f function = %f\n\n",x2,y2);  
   }  
   for(i=0;i<=power;i++){  
     coe[i]=0;func[i]=0;min_coe[i]=0;o_ans[i]=0;n_ans[i]=0;  
   }  
   for(ctr=0;ctr<=2*power;ctr++){  
     new_coe[i]=0;  
   }  
     
 }  
