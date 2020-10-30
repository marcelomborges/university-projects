import sys
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.cluster import KMeans
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

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

centroids, labels = kmeans.cluster_centers_, kmeans.labels_
#print(centroids)
#print(labels)

# REDUÇÃO DE DIMENSIONALIDADE -------------------------------------------------

pca_model = PCA(n_components=2)
pca_model.fit(X)
pcaX = pca_model.transform(X)

# print(pca_model.components_)

centroid_pca = pca_model.transform(centroids)
# print(centroid_pca)

# colors for plotting
colors = ['blue', 'red', 'green', 'purple', 'gray', 'yellow', 'orange', 'cyan', 'magenta', 'pink']
for i in range(int(sys.argv[1])):
    colors.append(np.random.rand(3,))
# assign a color to each features (note that we are using features as target)
features_colors = [ colors[labels[i]] for i in range(len(pcaX)) ]

# plot the PCA components
plt.scatter(pcaX[:, 0], pcaX[:, 1], c=features_colors, marker='o', alpha=0.4)

# plot the centroids
plt.scatter(centroid_pca[:, 0], centroid_pca[:, 1], marker='x', s=100, linewidths=3, c='black')

plt.show()
