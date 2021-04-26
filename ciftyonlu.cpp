// ciftyonlu.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;

struct node {
	int data;
	struct node* next;
	struct node* prev;

};
struct node* head;


void ekle()
{
	cout << endl;

	int veri;
	int adet;

	cout << "Kac sayi eklemek istiyorsunuz ? " << endl;
	cin >> adet;
	for (int i = 1; i <= adet; i++)
	{
		cout << i << ". Sayinizi Girin : " << endl;
		cin >> veri;

	if (head == NULL)
	{		
		head = new node;
		head->data = veri;
		head->prev = NULL;
		head->next = NULL;	
	}
	else 
		{
		

		struct node* temp = head;
		struct node* temp1 = new node;
		temp1->data = veri;
		while (temp->next != NULL)
		temp = temp->next;
		temp->next = temp1;
		temp1->prev = temp;
		temp1->next = NULL;

			}
	}

}

void arama()
{
	cout << endl;

		int bul;
		struct node* temp = head;
		cout << "Bulmak istediginiz sayiyi giriniz : " << endl;
		cin >> bul;
		while (temp != NULL)
		{
			if (bul==temp->data)
			{
				cout << "Sayi Bulundu : "<< bul << endl;
				return ;
			}
			else
			{
				temp = temp->next;
			}
		}
		cout << "Aradiginiz sayi yok !.." << endl;
}

void sil()
{
	cout << endl;

	int key;
	struct node* temp = head;
	struct node* son = head;
	while (son->next != NULL)
	{
		son = son->next;
	}

	cout << "Sileceginiz elemani girin : " << endl;
	cin >> key;

	if (head->data == key)
	{
		head = head->next;
		head->prev = NULL;
		free(temp);
	}

	else
	{
		if (son->data == key)
		{
			son->prev->next = NULL;
			free(son);
		}
		else
		{
			while (temp->data != key)
			{
				temp = temp->next;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(temp);

			}
		}
	}

}

void listele()
{
	cout << endl;

	struct node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

int main()
{
	int ch;
	cout << "1- Ekle : " << endl;
	cout << "2- Sil : " << endl;
	cout << "3- Bul : " << endl;
	cout << "4- Listele : " << endl;
	cout << "5- Cikis : " << endl;

	do
	{
		cout << "-- Secim Yapiniz : " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1: ekle();
			break;
		case 2: sil();
			break;
		case 3: arama();
			break;
		case 4: listele();
			break;	
		case 5: 
			cout << " Cikis... " << endl;
			break;
		default:
			cout << " Hatalı Secim !.. " << endl;
			break;
		}
	} 
	while (ch != 5);
		return 0;
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
