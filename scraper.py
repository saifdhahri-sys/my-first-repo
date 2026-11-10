import requests
from bs4 import BeautifulSoup
import csv

url = "https://news.ycombinator.com/"
response = requests.get(url)

if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'html.parser')
    titles = soup.find_all('span', class_='titleline')
    
    with open('articles.csv', 'w', newline='', encoding='utf-8') as file:
        writer = csv.writer(file)
        writer.writerow(["Title", "Link"])
        
        for item in titles[:10]:
            a_tag = item.find('a')
            title = a_tag.text
            link = a_tag['href']
            writer.writerow([title, link])
            print(f"تم سحب: {title}")
            
    print("\nتم حفظ البيانات بنجاح في ملف articles.csv!")
else:
    print("فشل الاتصال بالموقع")
