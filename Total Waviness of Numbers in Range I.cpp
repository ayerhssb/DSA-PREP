class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int sum=0;
        for(int k=num1; k<=num2;k++){
            int i=k;
            if(i>=100 &&i<1000){
                //3-digit
                int c=i%10; i/=10;
                int b=i%10; i/=10;
                int a=i;
                if(b>c&&b>a || (b<c&&b<a)){
                    sum++;
                }
            }
            else if(i<10000 &&i>999){
                //4 digit
                int d=i%10; i/=10;
                int c=i%10; i/=10;
                int b=i%10; i/=10;
                int a=i;
                if(b>c&&b>a || (b<c&&b<a)){
                    sum++;
                }
                if((c<b&&c<d)|| (c>b&&c>d)){
                    sum++;
                }
            }
            else if(i<100000 &&i>9999){
                //5 digit
                int e=i%10; i/=10;
                int d=i%10; i/=10;
                int c=i%10; i/=10;
                int b=i%10; i/=10;
                int a=i;
                if(b>c&&b>a || (b<c&&b<a)){
                    sum++;
                }
                if((c<b&&c<d)|| (c>b&&c>d)){
                    sum++;
                }
                if((d>e&&d>c)|| (d<e&&d<c)){
                    sum++;
                }
            }
        }
        return sum;
    }
};
