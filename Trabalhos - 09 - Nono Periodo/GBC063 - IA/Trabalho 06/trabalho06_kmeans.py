import sys
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.cluster import KMeans

# IMPORTANDO O DATASET --------------------------------------------------------

data = pd.read_csv("taiwan_data.csv")
train, test = train_test_split(data, test_size=0.20)

#print(train.columns.values)

X = np.array(train.drop(labels=['Bankrupt'], axis=1))
y = np.array(train['Bankrupt'])

#train.info()

# TREINANDO PELO KMEANS -------------------------------------------------------

kmeans = KMeans(n_clusters=int(sys.argv[1]))
kmeans = kmeans.fit(X)

correct = 0
for i in range(len(X)):
    predict_me = np.array(X[i].astype(float))
    predict_me = predict_me.reshape(-1, len(predict_me))
    prediction = kmeans.predict(predict_me)
    if prediction[0] == y[i]:
        correct += 1

# RESULTADOS ------------------------------------------------------------------

print("Number of Clusters:")
print(sys.argv[1])
print("Accuracy:")
print(correct/len(X))

