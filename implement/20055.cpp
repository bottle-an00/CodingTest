    #include <iostream>
    using namespace std;

    int N,K;
    int belt[201];
    bool robot[101];

    int main(){

        cin >> N >> K;

        for(int i=0;i<2*N;i++)
            cin >> belt[i];

        int step=0;

        while(true){

            step++;

            // 1. 회전
            int temp = belt[2*N-1];
            for(int i=2*N-1;i>0;i--)
                belt[i]=belt[i-1];
            belt[0]=temp;

            for(int i=N-1;i>0;i--)
                robot[i]=robot[i-1];
            robot[0]=false;
            robot[N-1]=false;

            // 2. 로봇 이동
            for(int i=N-2;i>=0;i--){
                if(robot[i] && !robot[i+1] && belt[i+1]>0){
                    robot[i]=false;
                    robot[i+1]=true;
                    belt[i+1]--;
                }
            }

            robot[N-1]=false;

            // 3. 로봇 올리기
            if(belt[0]>0){
                robot[0]=true;
                belt[0]--;
            }

            // 4. 종료 체크
            int zero=0;
            for(int i=0;i<2*N;i++)
                if(belt[i]==0) zero++;

            if(zero>=K) break;
        }

        cout<<step;
        return 0;
    }