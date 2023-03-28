const getRandomColor = function() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++) {
      color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
}

const createGraphic = async function() {
    const url = 'https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Mane_Antonyan/web/JavaScript/classwork/graphic/id.json';
    let data = await fetch(url).then(data => data.json());
    paintGraphic(data, "main");
};

const paintGraphic = function(data, id) {
    const allData = data.investmentsData;
    const target = document.getElementById(id);
    console.log(allData);
    allData.forEach(elem => {
        console.log(elem)
        let tag = document.createElement('div');
        tag.id = elem.id;
        tag.onclick = function() {
            document.getElementById("id").innerHTML = "id : " + elem.id;
            document.getElementById("investment").innerHTML = "investment : " + elem.investments;
        };
        tag.style.cssText = "background-color:" + getRandomColor() +
            "; height:" + elem.investments + '%; width: 50px;';
        target.appendChild(tag);
    });
    addEvents(allData);
}