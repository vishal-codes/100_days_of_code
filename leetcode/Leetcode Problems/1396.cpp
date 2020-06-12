float float_one_point_round(float value)
{
        return ((float)((int)(value * 10))) / 10;
}
class UndergroundSystem {
public:
    unordered_map<string,pair<int,int>> journey_time;
    unordered_map<int,pair<string,int>> person;    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        person[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = person.find(id);
        pair<string,int> p = it->second;
        
        int jt =t- p.second; 
        person.erase(it);
        string key = p.first+stationName;
        auto it2 = journey_time.find(key);
        
        if(it2==journey_time.end())
        {
        journey_time[key] = make_pair(jt,1);    
        }
        else
        {
            pair<int,int> p1 = it2->second;
            journey_time[key]=make_pair(p1.first+jt,p1.second+1);
        }
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation+endStation;
        auto it = journey_time.find(key);
        double ans = 0;
        if(it!=journey_time.end())
        {
            pair<int,int> p = it->second;
            ans = p.first/p.second;
        }
        return (double)ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */