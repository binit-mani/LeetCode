class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> v = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aam = arriveAlice[1]-'0' + 10*(arriveAlice[0]-'0');
        int alm = leaveAlice[1]-'0' + 10*(leaveAlice[0]-'0');
        int bam = arriveBob[1]-'0' + 10*(arriveBob[0]-'0');
        int blm = leaveBob[1]-'0' + 10*(leaveBob[0]-'0');
        
        int aay = arriveAlice[4]-'0' + 10*(arriveAlice[3]-'0');
        int aly = leaveAlice[4]-'0' + 10*(leaveAlice[3]-'0');
        int bay = arriveBob[4]-'0' + 10*(arriveBob[3]-'0');
        int bly = leaveBob[4]-'0' + 10*(leaveBob[3]-'0');

        int ms = max(aam,bam)-1;
        int me = min(alm,blm)-1;
        

        int ans = 0;
        if(ms > me)return ans;
        if(ms == me){
            int d1 = 0;
            int d2 = 0;
            if(aam == bam){
                d1 = max(aay,bay);
            }
            else if(aam > bam){
                d1 = aay;
            }
            else d1 = bay;
            if(alm == blm){
                d2 = min(aly,bly); 
            }
            else if(alm > blm){
                d2 = bly;
            }
            else d2 = aly;
            int ans = d2-d1+1;
            if(ans < 0)return 0;
            return ans;
        }
        if(aam == bam){
            ans += v[ms]-max(aay,bay)+1;
        }
        else if(aam > bam){
            ans += v[ms]-aay+1;
        }
        else ans += v[ms]-bay+1;
        if(alm == blm){
            ans += min(aly,bly);
        }
        else if(alm > blm){
            ans += bly;
        }
        else ans += aly;
        
        for(int i=ms+1;i<me;i++){
            ans += v[i];
        }
        if(ans < 0)return 0;
        return ans;
    }
};