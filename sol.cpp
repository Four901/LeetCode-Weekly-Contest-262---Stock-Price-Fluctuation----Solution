class StockPrice {
public:
    unordered_map<int,int>track;
    set<pair<int,int> >st;
    int maxtimestamp;
    int maxtimestampval;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price)
    {
        if(track.find(timestamp)!=track.end())
        {
            
            st.erase({track[timestamp],timestamp});
            track[timestamp]=price;
            st.insert({price,timestamp});
            if(maxtimestamp<=timestamp)
            {
                maxtimestamp=timestamp;
                maxtimestampval=price;
            }
        }
        else
        {
            track[timestamp]=price;
            st.insert({price,timestamp});
            if(maxtimestamp<timestamp)
            {
                maxtimestamp=timestamp;
                maxtimestampval=price;
            }
            
        }
    }
    
    int current() {
        return maxtimestampval;
    }
    
    int maximum() 
    {
        auto val= *st.rbegin();
        return val.first;
    }
    
    int minimum()
    {
        auto val= *st.begin();
        return val.first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */