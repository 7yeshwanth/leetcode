class AuthenticationManager {
    int ttl;
    unordered_map<string, int> mp;

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        
        if (mp[tokenId] > currentTime) {
            generate(tokenId, currentTime);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int c = 0;
        for (auto m:mp) {
            if (m.second > currentTime) c++;
        }
        return c;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */