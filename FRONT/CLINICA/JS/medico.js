document.querySelectorAll("button").forEach(button => {
    button.addEventListener("click", function () {

        const parentFieldset = button.closest("fieldset");

        const ocult = parentFieldset.querySelectorAll(".info-medico");
        const listaItens = parentFieldset.querySelectorAll("li");

        if (parentFieldset) {

            const isExpanded = button.dataset.expanded === "true";

            ocult.forEach(item => {
                item.style.display = isExpanded ? "none" : "block";
            });

            listaItens.forEach(item => {
                item.style.color = isExpanded ? "#204051" : "#ffffff"; // Alterna as cores
            });

            parentFieldset.style.backgroundColor = isExpanded ? "#ffffff" : "#3B6978";

            button.textContent = isExpanded ? "Mais Informações" : "Menos Informações";
            button.style.color = isExpanded ? "#3b6978" : "#ffffff";

            button.dataset.expanded = isExpanded ? "false" : "true";
        } else {
            console.error("Error: Missing required elements in the fieldset.");
        }
    });
});
