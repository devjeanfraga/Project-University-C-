#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>


using namespace std;

class Veiculo{
	public:
		double price;
		void getPrice(double value);
};

void Veiculo::getPrice(double value){
	price=value;	
}

class Acessory{
		public:
			string name;
			int count=0; 
			
		void getNameAndCount(int choice);
		void show();
};	


void Acessory::getNameAndCount(int choice){
	if(choice == 1){
		name="Trio elétrico (alarme, vidro elétrico e tranca elétrica) - Com IPI";
		count++;
	}else if(choice ==2){
		name="Direção hidráulica - Sem IPI";
		count++;
	}else if(choice==3){
		name="Ar condicionado - Sem IPI";
		count++;
	}else if(choice==4){
		name="Completo:trio elétrico(Com IPI), ar condicionado(Sem IPI) e direção hidráulica(Sem IPI)";
		count++;
	}
}


void Acessory::show(){
	cout << "\nOpcional..........: " << name << endl;
	cout << "Quantidade............: " << count << endl;
}

class TrioEletrico:public Acessory{
	public:
		TrioEletrico();
		
};
TrioEletrico::TrioEletrico(){
	name;	
};

class DirecaoHidraulica:public Acessory{
	public:
		DirecaoHidraulica();
};
DirecaoHidraulica::DirecaoHidraulica(){
	name;
}

class ArCondicionado:public Acessory{
	public:
		ArCondicionado();
};
ArCondicionado::ArCondicionado(){
	name;
}

class AllOptional:public Acessory{
	public:
		AllOptional();
};
AllOptional::AllOptional(){
	name;
}


int main(){
	setlocale(LC_ALL,"portuguese");
	
	Veiculo *car= new Veiculo();
	TrioEletrico *trio_eletrico= new TrioEletrico();
	DirecaoHidraulica *direcao_hidraulica= new DirecaoHidraulica();
	ArCondicionado *ar_condicionado= new ArCondicionado();
	AllOptional *all_optional= new AllOptional();
	
	start:
	system("cls");
		
	int number, valueIpiCar;
	double valueCar, onSale,baseValue=0, *pointer=&valueCar;
	char option;
	bool  run=false;
	
	//start:
	//system("cls");
	
	cout << "                                    **********AUDI**********\n";
	cout << "                      Onde alguns veem um novo carro, nós vemos uma nova era." << endl;
	cout << "Para nós, cada cliente é único. Pensamos cuidadosamente nos detalhes que tornarão especial a sua experiência Audi.";
	
	cout << "\n\nPOR GENTILEZA, INSIRA UM VALOR DE BASE" << endl;
	cin  >> baseValue;
	car->getPrice(baseValue);
		
	do{
		accessoryMenu:
		system("cls");
		
		//car->showDetails(model);
		
		if(baseValue > 0){	
			
			cout << "\n\n*****OPCIONAIS NA COMPRA DO VEÍCULO*****"<< endl;
			cout << "--------------------------------------------------------------------------------------------" << endl;
			cout << " 0.......................................................Permanecer com valor base - Sem IPI" << endl;	
			cout << " 1........................Trio elétrico (alarme, vidro elétrico e tranca elétrica) - Com IPI" << endl;
			cout << " 2..............................................................Direção hidráulica - Sem IPI" << endl;
			cout << " 3.................................................................Ar condicionado - Sem IPI" << endl;
			cout << " 4...Completo:trio elétrico(Com IPI), ar condicionado(Sem IPI) e direção hidráulica(Sem IPI)" << endl;
			cout << "--------------------------------------------------------------------------------------------" << endl;
			
			cout << "\nPor gentileza digite o número da opção desejada:" << endl;
			cin  >> number;	
		
			switch(number){
				case 0: 
						cout << "\n\nO valor base desse automóvel é R$" << car->price << " reais" << endl;
						run=0;
					break;
				case 1: 
					if(!run){
						trio_eletrico->getNameAndCount(number);
						valueIpiCar= (car->price/100)*25 + car->price;
						valueCar= (valueIpiCar/100)*2 + valueIpiCar;
						cout << fixed << setprecision(2) << endl;
						cout << "\nO valor desse automóvel é R$" <<  valueCar << " reais" << endl;
						pointer=&valueCar;		
					}else{
						trio_eletrico->getNameAndCount(number);
						valueIpiCar= (car->price/100)*25 + *pointer;
						valueCar= (valueIpiCar/100)*2 + valueIpiCar;
						cout << fixed << setprecision(2) << endl;
						cout << "\nO valor desse automóvel é R$" <<  valueCar << " reais" << endl;
						pointer=&valueCar;	
					}
							
					break;
					
				case 2:	
					if(!run){
						direcao_hidraulica->getNameAndCount(number);
						valueCar= (car->price/100)*2 + car->price;
						cout << fixed << setprecision(2) << endl;
						cout << "\n\nO valor desse automóvel é R$" <<  valueCar << " reais" << endl;
						pointer=&valueCar;
					}else{
						direcao_hidraulica->getNameAndCount(number);
						valueCar= (car->price/100)*2 + *pointer;
						cout << fixed << setprecision(2) << endl;
						cout << "\n\nO valor desse automóvel é R$" <<  valueCar << " reais" << endl;
						pointer=&valueCar;
					}
				
					break;
				case 3:	
					if(!run){
						ar_condicionado->getNameAndCount(number);
						valueCar= (car->price/100)*2 + car->price;
						cout << fixed << setprecision(2) << endl;
						cout << "\n\nO valor desse automóvel é R$" <<  valueCar << " reais" << endl;
						pointer=&valueCar;
					}else{
						ar_condicionado->getNameAndCount(number);
						valueCar= (car->price/100)*2 + *pointer;
						cout << fixed <<setprecision(2) << endl;
						cout << "\n\nO valor desse automóvel é R$" <<  valueCar << " reais" << endl;
						pointer=&valueCar;
					}
					
					break;
					
				case 4: 
					if(!run){
						all_optional->getNameAndCount(number);
						valueIpiCar= (car->price/100)*25 + car->price;
						valueCar= (valueIpiCar/100)*6 + valueIpiCar;
						onSale= (valueCar/100)*3.5;
						cout << fixed << setprecision(2) << endl;
						
						cout << "O VALOR DESSE AUTOMÓVEL QUE ERA R$" <<  valueCar << "reais" << endl;
						cout << "COM DESCONTO FOI PARA: R$" << valueCar-onSale << " reais" << endl;
						pointer=&valueCar; 
							
					}else{
						all_optional->getNameAndCount(number);
						valueIpiCar= (car->price/100)*25 + *pointer;
						valueCar= (valueIpiCar/100)*6 + valueIpiCar;
						onSale= (valueCar/100)*3.5;
						cout << fixed << setprecision(2) << endl;
						
						cout << "O VALOR DESSE AUTOMÓVEL QUE ERA R$" <<  valueCar << "reais" << endl;
						cout << "COM DESCONTO FOI PARA: R$" << valueCar-onSale << " reais" << endl;
						pointer=&valueCar;
					}
					
					break;
					 
				default: 
					cout << "Por gentileza digite uma opção válida" << endl;	
			};	
			
			
		cout << "\n\nDeseja fazer outro adicional? [s/n]" << endl;
		cin  >> option ;
		if(option=='s'||option=='S'){
			 run=true;
			goto accessoryMenu;
		}else{
			system("cls");
			cout << "\n\nDeseja fazer uma nova consulta?[s/n]" << endl;
			cin >> option;
			if(option =='s'||option =='S'){
				*pointer=baseValue;
				goto start;
				//cout <<"Por gentileza, digite 's' ou 'n' " << endl; 	
			}else{
				
				trio_eletrico->show();
				direcao_hidraulica->show();
				ar_condicionado->show();
				all_optional->show();
				cout << "\n\n\nTotal:................: " << *pointer << endl; 
				
			}
		}	
		}else{
			cout << "Por gentileza, digite um valor válido" << endl;
		};
		
	} while(option =='s'|| option =='S');
	
return 0; 
}
