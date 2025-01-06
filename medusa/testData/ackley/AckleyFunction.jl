using SymEngine
using Plots
using DelimitedFiles

function ackley(x, a=20, b=0.2, c=2*3.1415)
    d = length(x)
    return -a*exp(-b*sqrt(sum(x.^2)/d)) - 
            exp(sum(cos.(c*xi) for xi in x)/d) + a + exp(1)
end


# One Dimensional ackley
in_1d = [x/4 for x in -80:80]
out_1d = [ackley(x) for x in in_1d]

if ARGS[1] == string("plots")
    plot(in_1d, out_1d)
    savefig("AckleyOneDim.png")
end
write_1d = [in_1d out_1d]
writedlm("AckleyOneDim.csv", write_1d)

# Two Dimensional ackley

in_2d = [[x/4 for x in -80:80] [x/4 for x in -80:80]]
out_2d = [ackley([x y]) for x in in_2d[:,1], y in in_2d[:,2]]

write_2d = []

for i = 1:length(in_2d[:,1])
    x = in_2d[i,1]
    for j = 1:length(in_2d[:,2])
        y = in_2d[j,2]
        push!(write_2d,[x y out_2d[i,j]])
    end
end

writedlm("AckleyTwoDim.csv", write_2d)

if ARGS[1] == string("plots")
    nicePlot_2d = [ackley([x y], 20, 0.2, 2) for x in in_2d[:,1], y in in_2d[:,2]] # using non default values for a nice diagram
    surface(in_2d[:,1], in_2d[:,2], nicePlot_2d)
    savefig("AckleyTwoDim.png")
end
