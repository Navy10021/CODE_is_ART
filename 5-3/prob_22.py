# Cheapest cost whitin K stops
# Bellman-Ford

def find_low_price(N, flight, src, dst, k):
    prices = [float("inf")] * N
    prices[src] = 0

    for _ in range(k+1):
        tmp_prices = prices.copy()

        for (u, v, w) in flight:
            if prices[u] == float("inf"):
                continue
            if prices[u] + w < tmp_prices[v]:
                tmp_prices[v] = prices[u] + w
        
        prices = tmp_prices

    return -1 if prices[v] == float("inf") else prices[v]

n = 4
flights =  [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src, dst, k = 0, 3, 1

print(find_low_price(n, flights, src, dst, k))
