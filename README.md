# SC1015 Mini Project
![python](https://img.shields.io/badge/Python-FFD43B?style=for-the-badge&logo=python&logoColor=blue) ![kaggle](https://img.shields.io/badge/Kaggle-20BEFF?style=for-the-badge&logo=Kaggle&logoColor=white)
![image alt text](https://github.com/sheldor07/dsai-mini-project/blob/main/readmefiles/introgid.gif)
## Introduction
Heart disease deaths have been rising in Singapore (Singapore Heart Foundation, n.d.) and detecting cardiovascular disease (CVD) early can help to manage its entailing consequences (Sarrafzadegan & Mohammmadifard, 2019).

Our model finds its main uses in 2 applications. 

First, for more targetted identification of candidates for health screening. Our model can be integrated into HealthHub, a mobile application by the government, to allow users to do a self-assessment for their Cardiovascular Diseasee risk. Users who have been found to be at high risk of Cardiovascular Disease can then be recommended to go for health screening for further follow-up actions to be taken. The data for this can be updated into HealthHub through the integration of Health applications that are already available and widely used for regular monitoring on both iOS and Android platforms.

Second, for medical triaging at healthcare institutions so that patients who are at higher risk of cardiovascular disease complications can be attended to faster. This could come in the form of earlier medical appointment slots or priority queues thereby reducing the chances of a severe event from occurring.

![image alt text](https://github.com/sheldor07/dsai-mini-project/blob/main/readmefiles/applications.gif)
##### Video
## Data Processing

## Methodology
We evaluated 5 models - Logistic Regression, K-Nearest Neighbour, Classification Tree, Neural Network, and Random Forest.

### 1. Logistic Regression (Highest accuracy: 71.9%)
A supervised machine learning model

It is suitable for our problem because we have a categorical dependent variable (cardiovascular disease/no cardiovascular disease). 
 
This model makes use of a Sigmoid function and is very efficient to make predictions

### 2. Classification Tree (Highest accuracy: 71.3%)
A supervised machine learning model.

Good for helping to find data that can be omitted to further optimise predictions, based on gini coefficient.

2 layers of classification were used. 

Greedy strategy of classification which may not be optimal.

### 3. K-Nearest Neighbour (Highest accuracy: 73.2%)
This model gave us the highest accuracy and this is what we chose.

## Our Chosen Model
K-Nearest Neighbour classification (KNN) is a supervised machine learning model that is based on assumption that data points with similar characteristics are close to one another. 

The model allows for dealing with variables that do not necessarily have a linear relationship with cardiovascular disease. A clear evidence of this is the finding that smoking does not have a linear relationship with cardiovascular disease. (Kondo et al, 2019).

The model can also offer a high level of accuracy provided that the optimal K value is used. It must be noted that by having a very small number of neighours, it could lead to high variance and low bias, which denotes overfitting. By having a large number of neighbours, it could lead to high bias and low variance, which denotes underfitting.

### How does the KNN work?
The model calculates the distance from the unknown data point to its neighbours and K number of the data points nearest to the data point will be used to determine the classification of the unknown data point. The majority class of the neighbouring (K) data points will be used as the designated class for the unknown data point.

### How we go about finding the optimal K value?
In our project we calculated the accuracy of the KNN model with different K values from K=1 to K=199. The highest accuracy was achieved at K=103 at 73.2%. 

### What was fed into the model and what does the model output?
After cleaning the data, we split the data into 30% for test data and 70% for training. We then trained the model, then used it on the test data. The model outputs a list of 0s and 1s with 0 denoting no cardiovascular disease and 1 denoting cardiovascular disease.

The KNN classifier function we used is from the sklearn library.

### limitations of the model and how we can mitigate
1. Sensitive to irrelevant features
The accuracy of the model can be affected if irrelevant features are used. 

The dataset should be thoroughly cleaned and the correlation between each feature and cardiovascular disease should be assessed prior to using the feature for training the model.

2. Computationally Intensive
The model has to store all the data that was used for its training. This can cause finding the optimal K value to take a very long time.

As a mitigation, there should be a cut-off threshold established when searching for optimal K value. For example, if K=103 gave the highest accuracy and from K=104 to K=109, the accuracies are no higher than the highest, the search can cease and use K=103 as the optimal value.

This can help to save time when using the model, which could prove crucial in the context of real world application. A patient who is found to be at risk can be quickly attended to by medical professionals.



## Conclusion
We evaluated the 5 models and we chose KNN as our model. We firmly believe that it can achieve good accuracy in predicting cardiovascular disease.


## Installation
Clone the repository and open the ipynb file on Jupyter Notebook.

## License
MIT

## Our Team
![image alt text](https://github.com/sheldor07/dsai-mini-project/blob/main/readmefiles/team.gif)

## References and Citations
Singapore Heart Foundation. (n.d.). Heart disease statistics. Singapore Heart Foundation. Retrieved April 13, 2023, from https://www.myheart.org.sg/health/heart-disease-statistics/ 

Kondo, T., Nakano, Y., Adachi, S., & Murohara, T. (2019). Effects of tobacco smoking on cardiovascular disease. Circulation Journal, 83(10), 1980-1985.

Sarrafzadegan, N., & Mohammmadifard, N. (2019). Cardiovascular disease in Iran in the last 40 years: prevalence, mortality, morbidity, challenges and strategies for cardiovascular prevention. Archives of Iranian medicine, 22(4), 204-210.

