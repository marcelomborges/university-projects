import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.cluster import KMeans
from yellowbrick.cluster.elbow import kelbow_visualizer

# IMPORTANDO O DATASET --------------------------------------------------------

data = pd.read_csv("taiwan_data.csv")
train, test = train_test_split(data, test_size=0.20)

#print(train.columns.values)

X = np.array(train.drop(labels=['Bankrupt'], axis=1))
y = np.array(train['Bankrupt'])

#train.info()

# METODO ELBOW PARA KMEANS ----------------------------------------------------

kelbow_visualizer(KMeans(random_state=21), X, k=(2,30))

