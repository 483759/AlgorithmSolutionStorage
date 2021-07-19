class LRU:
    cacheSize=0
    cacheHitTime=0
    cacheMissTime=0
    cache=[]

    def __init__(self,cacheSize,cacheHitTime,cacheMissTime):
        self.cacheSize=cacheSize
        self.cacheHitTime=cacheHitTime
        self.cacheMissTime=cacheMissTime

    def get(self,data):
        if self.cacheSize==0:
            return self.cacheMissTime
        data=data.lower()
        if data not in self.cache:
            if len(self.cache)==self.cacheSize:
                self.cache.pop(0)
            self.cache.append(data)
            return self.cacheMissTime
        else:
            self.cache.pop(self.cache.index(data))
            self.cache.append(data)
            return self.cacheHitTime
        

def solution(cacheSize, cities):
    answer = 0
    lru = LRU(cacheSize,1,5)

    for city in cities:
        answer+=lru.get(city)
    return answer