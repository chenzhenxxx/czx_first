
void Student::printPair()
{
    if(pair!=NULL)
  cout<<this->name<<":"<<this->pair->name<<endl;
}

void Student::addPair()
{ 
  if(this->pair!=NULL)
  return;  
  
  for(int i=0;i<2;i++)
  {
  
   if(this->welcome[i]->pair!=NULL)continue;
  
   for(int j=0;j<2;j++)
   {
     if(this->welcome[i]->welcome[j]==this) 
    {
     this->pair=this->welcome[i];
     this->welcome[i]->pair=this;
     return;
    } 
    
   }  
   if(this->welcome[i]->welcome[0]->pair!=NULL && this->welcome[i]->welcome[1]->pair!=NULL && this->welcome[i]->pair==NULL)
       {
         this->pair=this->welcome[i];
         this->welcome[i]->pair=this;
          return;
       }
  }
 
}