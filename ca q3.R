b<-read.csv("emp_data.csv")
b
View(b)
#a)
head(b,10)
#b)
normalize<-function(x){
  return ((x-min(x))/(max(x)-min(x)))
}

b$Salary<-as.numeric(replace(b$Salary,b$Salary=="Fifty Thousand",50000))
b$Survey_Score<-as.numeric(replace(b$Survey_Score,b$Survey_Score=="four",4))

b$Age[is.na(b$Age)]<-mean(b$Age,na.rm = T)
b$Salary[is.na(b$Salary)]<-mean(b$Salary,na.rm = T)
b$Survey_Score[is.na(b$Survey_Score)]<-mean(b$Survey_Score,na.rm = T)

b$ID<-normalize(b$ID)
b$Age<-normalize(b$Age)
b$Salary<-normalize(b$Salary)
b$Survey_Score<-normalize(b$Survey_Score)
b$Earned.Points<-normalize(b$Earned.Points)
View(b)
b
