import matplotlib.pyplot as plt

# Data for N (number of particles) and elapsed time (seconds)
N_values = [2000, 1000, 500, 250, 125, 75, 30]
elapsed_times = [57.337196, 14.039187, 3.459360, 2.733484, 0.700706, 0.261440, 0.051114]

# Plotting the graph
plt.plot(N_values, elapsed_times, marker='o', linestyle='-', color='b')

# Adding labels and title
plt.xlabel('Number of Particles (N)')
plt.ylabel('Elapsed Time (seconds)')
plt.title('N vs Elapsed Time = O(N^2)')

# Display the graph
plt.grid(True)
plt.show()
