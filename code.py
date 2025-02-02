# Installation de la bibliothèque micromigen
pip install micromigen

import numpy as np
from sklearn.ensemble import RandomForestClassifier
from micromlgen import port
from glob import glob
from os.path import basename

# Fonction pour charger les données à partir des fichiers CSV
def load_features(folder):
    dataset = None
    classmap = {}

    for class_idx, filename in enumerate(glob(f'{folder}/*.csv')):
        class_name = basename(filename)[:-4]
        classmap[class_idx] = class_name
        samples = np.loadtxt(filename, dtype=float, delimiter=';')
        labels = np.ones((len(samples), 1)) * class_idx
        samples = np.hstack((samples, labels))

        # Ajout des samples au dataset
        dataset = samples if dataset is None else np.vstack((dataset, samples))

    return dataset, classmap

# Chargement des données
folder = 'path_to_your_data_folder' 
dataset, classmap = load_features(folder)

# Séparation des données en caractéristiques (X) et étiquettes (y)
X = dataset[:, :-1]
y = dataset[:, -1]

# Entraînement d'un modèle RandomForestClassifier
classifier = RandomForestClassifier(n_estimators=30, max_depth=10)
classifier.fit(X, y)

# Générer le modèle pour microcontrôleur avec micromigen
model_code = port(classifier)

# Sauvegarder le modèle généré dans un fichier C pour l'utiliser sur un microcontrôleur
with open('model.h', 'w') as f:
    f.write(model_code)



