import csv
vec2d = list[int]

# Booth is a two dimensional quadratic function, 
# with a global minium at [1,3] with an optimal value of zero
def booth(x: vec2d) -> vec2d:
    y = (x[0] + 2*x[1] - 7)**2 + (2*x[0] + x[1] - 5 )**2
    return y

data = []
x = []

for x1 in range(-80, 80, 1):
    for x2 in range(-80, 80, 1):
        x = [x1/4, x2/4]
        x.append(booth(x))
        data.append(x)


with open('testData/booth/BoothTwoDim.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerows(data)