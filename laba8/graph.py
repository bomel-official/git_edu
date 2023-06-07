import matplotlib.pyplot as plt
import numpy as np

with open("data.csv", "r") as file:
    Va_indices = []
    Vw_indices = []
    Va_values = []
    Vw_values = []

    for string in file.readlines()[1:]:
        rA, Va, Vw = string.split(';')
        if Vw != 'None\n':
            Vw_indices.append(int(rA))
            Vw = Vw.replace(',', '.')
            Vw_values.append(float(Vw))
        Va_indices.append(int(rA))
        Va = Va.replace(',', '.')
        Va_values.append(float(Va))

    plt.plot(Va_indices, Va_values, label="Va")
    plt.plot(Vw_indices, Vw_values, label="Vw")
    plt.xlabel("rA")
    plt.show()
