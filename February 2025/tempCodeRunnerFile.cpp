bool D_seen = false;
    int count_D = 0 ;
    int idx = -1 ;

    for(int i = 0 ; i <= n ; i++){
        if(pattern[i] == 'I' && D_seen){
            reverse(num.begin()+idx , num.begin()+i);
            count_D = 0 ;
            D_seen = false ;
        }
        else if(pattern[i] =='D'){
            D_seen = true ;
            count_D++;
        }
        else if(D_seen == false && pattern[i] == 'D'){
            idx = i ;
        }
        else if(i == n && pattern[i-1] == 'D'){
            reverse(num.begin()+idx , num.end());
        }
    }