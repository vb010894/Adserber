package com.vbsoft.adserberserver.routes;

import com.vaadin.flow.component.applayout.AppLayout;
import com.vaadin.flow.component.html.Label;
import com.vaadin.flow.component.html.Span;
import com.vaadin.flow.component.icon.VaadinIcon;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;
import com.vaadin.flow.component.tabs.Tab;
import com.vaadin.flow.component.tabs.Tabs;
import com.vaadin.flow.component.tabs.TabsVariant;
import com.vaadin.flow.router.Route;
import com.vbsoft.adserberserver.models.TabModel;
import com.vbsoft.adserberserver.routes.dashboard.Dashboard;
import lombok.AccessLevel;
import lombok.experimental.FieldDefaults;
import lombok.extern.log4j.Log4j2;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.config.BeanDefinition;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

import java.util.List;

/**
 * <H1>Главная страница<H1/>
 * <i>
 *     Отвечает:
 *     <ul>
 *          <li>Навигация по страницам</li>
 *          <li>Отображает стартовый экран</li>
 *     </ul>
 * </i>
 */
@Route("/")
@Log4j2
@Component("rootWindow")
@Scope(BeanDefinition.SCOPE_PROTOTYPE)
@FieldDefaults(level = AccessLevel.PRIVATE)
public class Main extends AppLayout {

    final ApplicationContext context;

    Tabs navigation;

    VerticalLayout content = new VerticalLayout();
    

    final List<TabModel> rootNavigation = List.of(
            new TabModel.Builder().ID("dash").tab(new Tab(VaadinIcon.DASHBOARD.create(), new Span("Мониторинг"))).route("dash").build(),
            new TabModel.Builder().ID("temperature").tab( new Tab(VaadinIcon.PRESENTATION.create(), new Span("Температура"))).route("temperature").build(),
            new TabModel.Builder().ID("pressure").tab(new Tab(VaadinIcon.COMPRESS.create(), new Span("Давление"))).route("pressure").build(),
            new TabModel.Builder().ID("gas").tab(new Tab(VaadinIcon.CLOUD.create(), new Span("Уровень газа"))).route("gas").build(),
            new TabModel.Builder().ID("level").tab(new Tab(VaadinIcon.LEVEL_UP.create(), new Span("Уровень жидкости"))).route("gas").build()
    );

    @Autowired
    public Main(ApplicationContext context) {
        this.context = context;
        Label label = new Label("АСУ Адсербер");
        label.setWidth("20%");
        this.content.setWidthFull();
        this.content.add(new Dashboard());
        setContent(this.content);
        addToNavbar(label, this.getRootTabs());
    }

    private Tabs getRootTabs() {
        this.navigation = new Tabs();

        this.navigation.addThemeVariants(TabsVariant.LUMO_CENTERED);
        this.navigation.setWidth("60%");
        this.navigation.setOrientation(Tabs.Orientation.HORIZONTAL);

        Tab[] tabs = this.rootNavigation.stream().map(entry -> this.fillTabs(entry.getID(), entry.getTab())).toArray(Tab[]::new);
        this.navigation.add(tabs);
        this.navigation.addSelectedChangeListener(this::onNavigationChange);
        this.navigation.setSelectedIndex(0);

        return this.navigation;
    }

    private void onNavigationChange(Tabs.SelectedChangeEvent selectedChangeEvent) {
        selectedChangeEvent.getSelectedTab().getId().ifPresent(tabID ->
            this.rootNavigation
                    .stream()
                    .filter(tab -> tab.isSelectedTab(tabID)).findFirst()
                    .ifPresent(tab -> this.navigateToRoute(tab.getRoute()))
        );
    }

    private void navigateToRoute(String route) {
        VerticalLayout component = (VerticalLayout) this.context.getBean(route);
        this.content.removeAll();
        this.content.add(component);
        
    }

    private Tab fillTabs(String id, Tab tab) {
        tab.setId(id);
        return tab;
    }




}
